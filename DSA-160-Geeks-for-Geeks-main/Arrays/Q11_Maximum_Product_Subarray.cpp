#include <iostream>
#include <vector>
using namespace std;

/*
    ----------------------- Maximum Product Subarray -----------------------

    Given an array arr[] that may contain:
        - positive numbers
        - negative numbers
        - zeros

    Find the MAXIMUM PRODUCT of any contiguous subarray.

    Important:
        - The answer always fits in a 32-bit integer.
        - A subarray is continuous.
        - Negative numbers can flip the result.
        - Zeros break the subarray.

    Approach:
        We maintain:
            currMax = maximum product ending at current index
            currMin = minimum product ending at current index
        Because:
            - Negative * negative = positive
            - Negative * positive = negative

        For each element arr[i]:
            if arr[i] < 0:
                swap(currMax, currMin)
           
            currMax = max(arr[i], currMax * arr[i])
            currMin = min(arr[i], currMin * arr[i])

            ans = max(ans, currMax)

    Example:
        arr = [-2, 6, -3, -10, 0, 2]
        Maximum product subarray = [6, -3, -10]
        Product = 180

--------------------------------------------------------------------------- */

class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();

        int currMax = arr[0];
        int currMin = arr[0];
        int ans = arr[0];

        for (int i = 1; i < n; i++) {

            // If current element is negative, swap max and min
            if (arr[i] < 0)
                swap(currMax, currMin);

            currMax = max(arr[i], currMax * arr[i]);
            currMin = min(arr[i], currMin * arr[i]);

            ans = max(ans, currMax);
        }

        return ans;
    }
};

// ----------------------------- MAIN FUNCTION ---------------------------------

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Solution obj;
    cout << "Maximum Product Subarray = " << obj.maxProduct(arr) << endl;

    return 0;
}
