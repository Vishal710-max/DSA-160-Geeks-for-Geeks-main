#include <iostream>
#include <vector>
using namespace std;

/*
    ------------------- Problem: Move All Zeroes to End -------------------

    You are given an array arr[] of non-negative integers.
    You have to move all the zeros in the array to the right end while
    maintaining the relative order of the non-zero elements.

    Important:
    - Operation must be performed IN PLACE.
    - Do NOT use extra space for another array.

    Example:
    Input:  [1, 2, 0, 4, 3, 0, 5, 0]
    Output: [1, 2, 4, 3, 5, 0, 0, 0]

    Input:  [10, 20, 30]
    Output: [10, 20, 30]

    Input:  [0, 0]
    Output: [0, 0]

-------------------------------------------------------------------------------
*/

class Solution {
public:
    // Function to push all zeroes to the end of the array
    void pushZerosToEnd(vector<int>& arr) {
        int j = 0; // pointer for next non-zero element

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
};


int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    obj.pushZerosToEnd(arr);

    cout << "Array after moving zeros to end: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
