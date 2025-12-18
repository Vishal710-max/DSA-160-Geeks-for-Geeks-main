#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    ------------------------ Problem: Majority Element - More Than n/3 ------------------------

    Given an array arr[] of integers, find all elements that appear MORE THAN floor(n/3) times.
    The result must be returned in SORTED order.

    Key Observations:
    - There can be at most 2 such elements.
    - This is solved using the extended Boyer-Moore Voting Algorithm.

    Steps:
    1) Find two potential candidates using vote cancellation.
    2) Count their frequencies.
    3) Add those which appear more than n/3 times.

    Examples:

    Input:  [2, 2, 3, 1, 3, 2, 1, 1]
    Output: [1, 2]
    Explanation: 1 appears 3 times, 2 appears 3 times (> 8/3 = 2)

    Input:  [-5, 3, -5]
    Output: [-5]

    Input:  [3, 2, 2, 4, 1, 4]
    Output: []
    Explanation: No element appears more than floor(6/3) = 2 times.

-----------------------------------------------------------------------------------------------
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n = arr.size();

        // Step 1: Find potential candidates
        int c1 = 0, c2 = 0;
        int v1 = INT_MIN, v2 = INT_MIN;

        for (int x : arr) {
            if (x == v1) c1++;
            else if (x == v2) c2++;
            else if (c1 == 0) v1 = x, c1 = 1;
            else if (c2 == 0) v2 = x, c2 = 1;
            else c1--, c2--;
        }

        // Step 2: Count actual frequencies of candidates
        c1 = c2 = 0;
        for (int x : arr) {
            if (x == v1) c1++;
            else if (x == v2) c2++;
        }

        // Step 3: Add valid results
        vector<int> ans;
        if (c1 > n/3) ans.push_back(v1);
        if (c2 > n/3) ans.push_back(v2);

        sort(ans.begin(), ans.end());
        return ans;
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
    vector<int> res = obj.majorityElement(arr);

    cout << "Elements occurring more than floor(n/3) times: ";
    if (res.empty()) {
        cout << "[]";
    } else {
        for (int x : res) cout << x << " ";
    }

    cout << endl;
    return 0;
}
