#include <iostream>
#include <vector>
using namespace std;

/*
    ----------------------------- Insert Interval -----------------------------

    Geek has an array of non-overlapping intervals `intervals[][]` where
    intervals[i] = [start_i, end_i] represent the start and end of the i-th event.
    The array `intervals` is sorted in ascending order by start_i.

    You are given a new interval newInterval = [newStart, newEnd]. Insert
    newInterval into intervals such that the resulting list is still sorted
    by start and has no overlapping intervals (merge if necessary).

    Examples:
      Input:  intervals = [[1,3],[4,5],[6,7],[8,10]], newInterval = [5,6]
      Output: [[1,3],[4,7],[8,10]]
        Explanation: [5,6] overlaps with [4,5] and [6,7] → merged to [4,7]

      Input:  intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,9]
      Output: [[1,2],[3,10],[12,16]]
        Explanation: [4,9] overlaps with [3,5],[6,7],[8,10] → merged to [3,10]

    Approach:
      1) Add all intervals that end before newInterval starts (no overlap).
      2) Merge all intervals that overlap with newInterval by updating
         newInterval = [min(start, newStart), max(end, newEnd)].
      3) Add remaining intervals that start after newInterval ends.
      This is O(n) time and O(1) extra space (besides result array).

    Constraints:
      1 <= intervals.size() <= 1e5
      0 <= start_i <= end_i <= 1e9
      0 <= newStart <= newEnd <= 1e9
*/

class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> result;
        int n = intervals.size();
        int i = 0;

        int newStart = newInterval[0];
        int newEnd = newInterval[1];

        // 1) Add all intervals that end before newInterval starts (no overlap)
        while (i < n && intervals[i][1] < newStart) {
            result.push_back(intervals[i]);
            i++;
        }

        // 2) Merge all overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newEnd) {
            newStart = min(newStart, intervals[i][0]);
            newEnd = max(newEnd, intervals[i][1]);
            i++;
        }
        // push the merged newInterval
        result.push_back({newStart, newEnd});

        // 3) Add the remaining intervals
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

// ------------------------------ MAIN (for testing) ------------------------------
// Input format example:
// n
// s1 e1
// s2 e2
// ...
// sn en
// newStart newEnd
//
// Output: prints merged intervals, each line "start end"

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

    int ns, ne;
    cin >> ns >> ne;
    vector<int> newInterval = {ns, ne};

    Solution sol;
    vector<vector<int>> merged = sol.insertInterval(intervals, newInterval);

    for (auto &iv : merged) {
        cout << iv[0] << " " << iv[1] << "\n";
    }

    return 0;
}
