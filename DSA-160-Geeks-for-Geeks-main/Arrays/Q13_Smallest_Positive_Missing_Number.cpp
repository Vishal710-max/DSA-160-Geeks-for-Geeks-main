#include <iostream>
#include <vector>
using namespace std;

/*
    ------------------ Smallest Positive Missing Number ------------------

    You are given an integer array arr[]. Your task is to find the
    SMALLEST POSITIVE NUMBER missing from the array.

    Notes:
        • Positive numbers start from 1.
        • Array can contain negative numbers and zeros too.
        • Must be O(n) time and O(1) extra space.

    Examples:

    Input:  [2, -3, 4, 1, 1, 7]
    Output: 3

    Input:  [5, 3, 2, 5, 1]
    Output: 4

    Input:  [-8, 0, -1, -4, -3]
    Output: 1

    Constraints:
        1 ≤ arr.size() ≤ 10^5
        -10^6 ≤ arr[i] ≤ 10^6

    -------------------------------- Approach --------------------------------

    We want the smallest missing POSITIVE → map values into index:

          value x should be placed at index (x - 1)

    Algorithm:
        1. Ignore values <= 0 or > n.
        2. For valid positives, place arr[i] into its correct index position
           using swapping (cycle replacement).
        3. After placing:
               the first index i where arr[i] != i+1
               gives answer = i+1
        4. If all positions are correct → answer = n+1

    Example:
        arr = [2, 3, 7, 6, 8, 1]
        After placing:
            [1, 2, 3, ?, ?, ?]
        First mismatch at index 3 → answer = 4

--------------------------------------------------------------------------- */

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();

        // Step 1 & 2: Place all positives in their correct index (x → x-1)
        for (int i = 0; i < n; i++) {
            while (arr[i] >= 1 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        // Step 3: First index where value is wrong gives missing number
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1)
                return i + 1;
        }

        // Step 4: Everything is in place → answer is n+1
        return n + 1;
    }
};

// --------------------------- MAIN FUNCTION ---------------------------

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution obj;
    cout << "Smallest Positive Missing Number = " << obj.missingNumber(arr) << endl;

    return 0;
}
