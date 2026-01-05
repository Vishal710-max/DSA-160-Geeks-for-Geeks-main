#include <iostream>
#include <vector>
using namespace std;

/*
    ----------------------------- Count Inversions -----------------------------

    Given an array arr[], find the Inversion Count of the array.
    An inversion is a pair (i, j) such that i < j and arr[i] > arr[j].

    Examples:
      Input:  [2, 4, 1, 3, 5]
      Output: 3
      Explanation: inversions are (2,1), (4,1), (4,3)

      Input:  [2, 3, 4, 5, 6]
      Output: 0

      Input:  [10, 10, 10]
      Output: 0

    Constraints:
      1 <= arr.size() <= 1e5
      1 <= arr[i] <= 1e4

    Optimal approach:
      Use a modified Merge Sort to count inversions while merging.
      Time Complexity: O(n log n)
      Space Complexity: O(n)

    Note:
      The maximum possible number of inversions for n up to 1e5 is about 5e9,
      so store the count in a 64-bit integer (long long).
*/

class Solution {
public:
    // Merge two sorted halves and count cross inversions
    long long merge_count(vector<int> &a, vector<int> &tmp, int left, int mid, int right) {
        int i = left;      // pointer for left half
        int j = mid + 1;   // pointer for right half
        int k = left;      // pointer for tmp
        long long inv_count = 0;

        while (i <= mid && j <= right) {
            if (a[i] <= a[j]) {
                tmp[k++] = a[i++];
            } else {
                // a[i] > a[j] => all remaining elements from a[i..mid] are > a[j]
                tmp[k++] = a[j++];
                inv_count += (long long)(mid - i + 1);
            }
        }

        while (i <= mid) tmp[k++] = a[i++];
        while (j <= right) tmp[k++] = a[j++];

        for (int idx = left; idx <= right; ++idx) a[idx] = tmp[idx];

        return inv_count;
    }

    // Recursive merge sort that returns inversion count
    long long merge_sort_count(vector<int> &a, vector<int> &tmp, int left, int right) {
        if (left >= right) return 0LL;
        int mid = left + (right - left) / 2;
        long long cnt = 0;
        cnt += merge_sort_count(a, tmp, left, mid);
        cnt += merge_sort_count(a, tmp, mid + 1, right);
        cnt += merge_count(a, tmp, left, mid, right);
        return cnt;
    }

    // Public function to compute inversions
    long long inversionCount(vector<int> &arr) {
        int n = arr.size();
        if (n <= 1) return 0LL;
        vector<int> tmp(n);
        return merge_sort_count(arr, tmp, 0, n - 1);
    }
};

// ------------------------------- MAIN (for testing) -------------------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    Solution sol;
    long long ans = sol.inversionCount(arr);

    cout << ans << '\n';
    return 0;
}
