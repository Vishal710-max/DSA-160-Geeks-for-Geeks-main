#include <iostream>
#include <vector>
using namespace std;

/*
    ------------------------------ Problem: Next Permutation ------------------------------

    Given an array arr[] representing a permutation, generate the NEXT permutation
    which is lexicographically next greater.

    If NO next permutation exists (i.e., array is in descending order), rearrange
    it into the LOWEST possible order (sorted in ascending order).

    Steps:
    1. Find the first index 'i' from the right such that arr[i] < arr[i+1].
       (This is called the "breakpoint".)
    2. If no such index exists, reverse the whole array → sorted ascending.
    3. Otherwise, find the first index 'j' from the right such that arr[j] > arr[i].
    4. Swap arr[i] and arr[j].
    5. Reverse the elements from (i+1) to end.

    Examples:

    Example 1:
        Input:  [2, 4, 1, 7, 5, 0]
        Output: [2, 4, 5, 0, 1, 7]

    Example 2:
        Input:  [3, 2, 1]
        Output: [1, 2, 3]   (no next permutation exists → lowest order)

    Example 3:
        Input:  [3, 4, 2, 5, 1]
        Output: [3, 4, 5, 1, 2]

--------------------------------------------------------------------------------------------
*/

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int i = n - 2;

        // 1. Find first decreasing element from the right
        while (i >= 0 && arr[i] >= arr[i + 1]) {
            i--;
        }

        // 2. If breakpoint found
        if (i >= 0) {
            int j = n - 1;

            // Find element just larger than arr[i]
            while (arr[j] <= arr[i]) {
                j--;
            }

            swap(arr[i], arr[j]);
        }

        // 3. Reverse the remaining part
        reverse(arr.begin() + i + 1, arr.end());
    }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    obj.nextPermutation(arr);

    cout << "Next Permutation: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
