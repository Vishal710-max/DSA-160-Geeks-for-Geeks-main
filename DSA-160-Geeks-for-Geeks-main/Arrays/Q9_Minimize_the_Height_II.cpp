#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    ----------------------------- Minimize the Heights II -----------------------------

    Given an array arr[] of heights of n towers and an integer k.
    For EACH tower, you MUST modify its height by exactly ONE of:

        - Increase by k
        - Decrease by k

    After modification:
        - No height should become negative.
        - Find the MINIMUM possible difference between maximum and minimum height.

    Approach:
        1. Sort the array.
        2. Initially consider the difference as arr[n-1] - arr[0].
        3. Try making smallest become arr[0] + k, and largest become arr[n-1] - k.
        4. Evaluate every partition in sorted array.

    Example:
        k = 2, arr = [1, 5, 8, 10]
        Modified => [3, 3, 6, 8]
        Answer = 8 - 3 = 5

--------------------------------------------------------------------------------------
*/

class Solution {
public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 1) return 0;

        // Sort the array first
        sort(arr.begin(), arr.end());

        // Initial difference
        int ans = arr[n - 1] - arr[0];

        // New smallest and largest possible
        int smallest = arr[0] + k;
        int largest = arr[n - 1] - k;

        // Try modifying towers by splitting the array
        for (int i = 0; i < n - 1; i++) {
            int new_min = min(smallest, arr[i + 1] - k);
            int new_max = max(largest, arr[i] + k);

            if (new_min < 0) continue;    // Negative height not allowed

            ans = min(ans, new_max - new_min);
        }

        return ans;
    }
};

int main() {
    int n, k;
    cout << "Enter number of towers (n): ";
    cin >> n;

    cout << "Enter k: ";
    cin >> k;

    vector<int> arr(n);
    cout << "Enter tower heights: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution obj;
    int result = obj.getMinDiff(arr, k);

    cout << "Minimum possible difference after modification: " << result << endl;

    return 0;   
}
