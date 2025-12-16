#include <iostream>
#include <vector>
using namespace std;

/*
    -------------------- Problem: Second Largest Element --------------------

    You are given an array arr[] of positive integers.
    You must return the SECOND LARGEST element.

    Important:
    - The second largest element should NOT be equal to the largest element.
    - If the second largest does NOT exist, return -1.

    Examples:

    Input:  [12, 35, 1, 10, 34, 1]
    Output: 34
    Explanation: Largest = 35, Second Largest = 34

    Input:  [10, 5, 10]
    Output: 5
    Explanation: Largest = 10, Second Largest = 5

    Input:  [10, 10, 10]
    Output: -1
    Explanation: No second largest element exists.

-------------------------------------------------------------------------------
*/

class Solution {
public:
    int getSecondLargest(vector<int> &arr) {
        int largest = -1, second = -1;

        for (int x : arr) {
            if (x > largest) {
                second = largest;
                largest = x;
            }
            else if (x > second && x < largest) {
                second = x;
            }
        }

        return second;
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
    int ans = obj.getSecondLargest(arr);

    cout << "Second Largest Element: " << ans << endl;

    return 0;
}
