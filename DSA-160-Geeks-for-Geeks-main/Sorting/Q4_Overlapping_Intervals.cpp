#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    ---------------------------- Overlapping Intervals ----------------------------

    Given an array of intervals arr[][] where each interval is [start, end],
    merge all overlapping intervals and return the resulting list of disjoint
    intervals sorted by start time.

    Examples:
      Input:  [[1,3],[2,4],[6,8],[9,10]]
      Output: [[1,4],[6,8],[9,10]]
        Explanation: [1,3] and [2,4] overlap → merged to [1,4]

      Input:  [[6,8],[1,9],[2,4],[4,7]]
      Output: [[1,9]]
        Explanation: All intervals overlap into [1,9]

    Constraints:
      1 <= arr.size() <= 1e5
      0 <= start_i <= end_i <= 1e6

    Approach:
      1. Sort intervals by start.
      2. Iterate and merge when current.start <= lastMerged.end by updating
         lastMerged.end = max(lastMerged.end, current.end).
      3. Otherwise push current as a new merged interval.
    Complexity:
      Time: O(n log n) due to sort
      Space: O(n) for output
*/

class Solution {
public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        vector<vector<int>> result;
        if (arr.empty()) return result;

        // Sort by start time (and by end time implicitly)
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });

        // Start with the first interval
        vector<int> current = arr[0];

        for (size_t i = 1; i < arr.size(); ++i) {
            // If overlapping (current.end >= next.start), merge
            if (current[1] >= arr[i][0]) {
                current[1] = max(current[1], arr[i][1]);
            } else {
                // No overlap — push current and move to next
                result.push_back(current);
                current = arr[i];
            }
        }

        // Push the last interval
        result.push_back(current);

        return result;
    }
};

// ------------------------------- MAIN (for testing) -------------------------------
// Input format (example):
// n
// start1 end1
// start2 end2
// ...
// startn endn
//
// Output: merged intervals, each printed as "start end" on a new line.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> intervals;
    intervals.reserve(n);
    for (int i = 0; i < n; ++i) {
        int s, e;
        cin >> s >> e;
        intervals.push_back({s, e});
    }

    Solution sol;
    vector<vector<int>> merged = sol.mergeOverlap(intervals);

    for (auto &iv : merged) {
        cout << iv[0] << " " << iv[1] << "\n";
    }

    return 0;
}
