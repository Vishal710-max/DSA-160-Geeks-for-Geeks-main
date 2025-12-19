#include <iostream>
#include <vector>
using namespace std;

/*
    -------------------------------- Kadane's Algorithm --------------------------------

    You are given an integer array arr[]. You need to find the maximum sum of any
    contiguous subarray (subarray must contain at least one element).

    A subarray = continuous part of the array.

    Examples:

    Input: [2, 3, -8, 7, -1, 2, 3]
    Output: 11
    Explanation: The subarray [7, -1, 2, 3] has the largest sum 11.

    Input: [-2, -4]
    Output: -2
    Explanation: The subarray [-2] has the largest sum -2.

    Input: [5, 4, 1, 7, 8]
    Output: 25
    Explanation: The subarray [5, 4, 1, 7, 8] has the largest sum 25.

    Constraints:
    - 1 ≤ arr.size() ≤ 100000
    - -10000 ≤ arr[i] ≤ 10000

    Approach (Kadane's Algorithm):
        We maintain two values:
            curr = maximum sum ending at current index
            ans  = maximum sum seen so far

        For each element:
            curr = max(arr[i], curr + arr[i])
            ans  = max(ans, curr)

        This handles:
            ✔ positive numbers
            ✔ negative numbers
            ✔ mixed values
-----------------------------------------------------------------------------------------
*/

class Solution {
public:
    int maxSubarraySum(vector<int> &arr) {
        int curr = arr[0];
        int ans  = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            curr = max(arr[i], curr + arr[i]);  // start new or extend existing
            ans  = max(ans, curr);              // update global max
        }

        return ans;
    }
};

// ------------------------------- MAIN FUNCTION -------------------------------

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution obj;
    cout << "Maximum Subarray Sum = " << obj.maxSubarraySum(arr) << endl;

    return 0;
}
