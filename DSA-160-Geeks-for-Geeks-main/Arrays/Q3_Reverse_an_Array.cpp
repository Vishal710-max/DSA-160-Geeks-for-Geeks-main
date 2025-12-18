#include <iostream>
#include <vector>
using namespace std;

/*
    ------------------------- Problem: Reverse an Array -------------------------

    You are given an array arr[] of integers.
    Your task is to REVERSE the array.

    Note:
    - You must modify the array IN PLACE.
    - Do NOT use extra space for another array.

    Examples:

    Input:  [1, 4, 3, 2, 6, 5]
    Output: [5, 6, 2, 3, 4, 1]

    Input:  [4, 5, 2]
    Output: [2, 5, 4]

    Input:  [1]
    Output: [1]

-------------------------------------------------------------------------------
*/

class Solution {
public:
    void reverseArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    obj.reverseArray(arr);

    cout << "Reversed array: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
