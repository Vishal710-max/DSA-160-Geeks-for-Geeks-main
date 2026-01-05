#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    ------------------------------- Find H-Index -------------------------------

    You are given an array citations[], where each element citations[i]
    represents the number of citations received by the i-th paper of a researcher.
    Compute the researcher's H-index.

    Definition (H-index):
      The H-index is the maximum value H such that the researcher has published
      at least H papers that have each been cited at least H times.

    Examples:
      Input:  citations = [3, 0, 5, 3, 0]
      Output: 3
      Explanation: There are at least 3 papers with citations >= 3 (3,5,3).

      Input:  citations = [5, 1, 2, 4, 1]
      Output: 2
      Explanation: At least 2 papers have >= 2 citations but not 3 papers with >= 3.

      Input:  citations = [0, 0]
      Output: 0

    Constraints:
      1 <= citations.size() <= 1e6
      0 <= citations[i] <= 1e6

    Approach (simple & fast):
      1) Sort the array in descending order.
      2) Scan through sorted list and find the largest index i (0-based)
         such that citations[i] >= i+1. The H-index is i+1.
      Complexity: O(n log n) due to sorting. Works well within constraints.
-------------------------------------------------------------------------------
*/

class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        if (n == 0) return 0;

        // Sort in descending order
        sort(citations.begin(), citations.end(), greater<int>());

        // Find maximum h such that citations[h-1] >= h
        int h = 0;
        for (int i = 0; i < n; ++i) {
            if (citations[i] >= i + 1) h = i + 1;
            else break; // once condition fails for sorted desc, further i will also fail
        }
        return h;
    }
};

// ----------------------------- MAIN FUNCTION ---------------------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // Read number of papers
    if (!(cin >> n)) return 0;

    vector<int> citations(n);
    for (int i = 0; i < n; ++i) cin >> citations[i];

    Solution sol;
    int result = sol.hIndex(citations);

    cout << result << '\n';
    return 0;
}
