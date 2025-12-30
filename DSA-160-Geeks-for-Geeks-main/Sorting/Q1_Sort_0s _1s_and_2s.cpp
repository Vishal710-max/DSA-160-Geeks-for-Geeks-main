#include <iostream>
#include <vector>
using namespace std;
/*
-----------------------------------------
Problem: Sort 0s, 1s and 2s  
-----------------------------------------

Given an array arr[] consisting only of 0s, 1s, and 2s, 
sort the array in ascending order WITHOUT using any built-in sort function.

Example:
Input:  arr = [0, 1, 2, 0, 1, 2]
Output: [0, 0, 1, 1, 2, 2]

Example:
Input:  arr = [2, 1, 0]
Output: [0, 1, 2]

Constraints:
1 ≤ arr.size() ≤ 10^6
0 ≤ arr[i] ≤ 2

Goal:
Sort the array in **one pass** and **constant extra space**.

Solution Approach:
Use Dutch National Flag Algorithm:
- low   → boundary for 0s
- mid   → scanning pointer
- high  → boundary for 2s
-----------------------------------------
*/


class Solution {
public:
    void sort012(vector<int>& arr) {

        int low = 0, mid = 0, high = arr.size() - 1;

        // One-pass sorting
        while (mid <= high) {

            if (arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1) {
                mid++;  // Already in correct region
            }
            else { // arr[mid] == 2
                swap(arr[mid], arr[high]);
                high--;   // Do NOT move mid
            }
        }
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    obj.sort012(arr);

    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
