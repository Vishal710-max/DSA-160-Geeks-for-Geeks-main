#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
    ----------------------- Maximum Circular Subarray Sum -----------------------

    A circular array means the subarray can wrap around from the end to the start.

    Task:
        Find the MAXIMUM possible sum of a NON-EMPTY subarray.

    Two Possible Cases:

    1. NORMAL MAX SUBARRAY (Non-wrapping)
        Use Kadane's Algorithm:
            max_normal = maximum subarray sum

    2. WRAPPING SUBARRAY
        Maximum circular sum occurs when:
            total_sum - (minimum subarray sum)

        Because removing the minimum subarray leaves the maximum "wrapped" portion.

        To find minimum subarray:
            Use Kadane's but invert sign OR track min similarly.

    Special Case:
        If all elements are negative:
            The "wrap" case becomes invalid.
            Simply return the largest single element (Kadane normal result).

    Example:
        arr = [8, -8, 9, -9, 10, -11, 12]
        normal max = 12
        total_sum = 11
        min_subarray = -10
        wrap_max = total_sum - min_subarray = 21
        Answer = max(12, 22) = 22

-------------------------------------------------------------------------------
*/

class Solution {
public:
    // Standard Kadane (max subarray)
    int kadaneMax(vector<int>& arr) {
        int curr = arr[0], best = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            curr = max(arr[i], curr + arr[i]);
            best = max(best, curr);
        }
        return best;
    }

    // Kadane for minimum subarray
    int kadaneMin(vector<int>& arr) {
        int curr = arr[0], best = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            curr = min(arr[i], curr + arr[i]);
            best = min(best, curr);
        }
        return best;
    }

    int maxCircularSum(vector<int>& arr) {
        int n = arr.size();

        // 1. Normal max subarray sum
        int max_normal = kadaneMax(arr);

        // If all numbers are negative → return normal kadane
        if (max_normal < 0)
            return max_normal;

        // 2. Compute total sum and minimum subarray sum
        int total_sum = accumulate(arr.begin(), arr.end(), 0);
        int min_sub = kadaneMin(arr);

        int max_wrap = total_sum - min_sub;

        // Answer is the best of non-wrapping and wrapping subarray
        return max(max_normal, max_wrap);
    }
};

// ------------------------------- MAIN FUNCTION -----------------------------------

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution obj;
    cout << "Maximum Circular Subarray Sum = " << obj.maxCircularSum(arr) << endl;

    return 0;
}
