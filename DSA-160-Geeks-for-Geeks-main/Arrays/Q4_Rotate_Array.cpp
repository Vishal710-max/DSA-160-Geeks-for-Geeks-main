#include <iostream>
#include <vector>
using namespace std;

/*
    --------------------------- Problem: Rotate Array ---------------------------

    You are given an array arr[].
    Rotate the array to the LEFT (counter-clockwise) by d steps.
    The rotation must be done IN PLACE.

    Note:
    - Consider the array as circular.
    - d can be larger than the array size.

    Example 1:
        Input:  arr = [1, 2, 3, 4, 5], d = 2
        Output: [3, 4, 5, 1, 2]

    Example 2:
        Input:  arr = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
        Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]

    Example 3:
        Input:  arr = [7, 3, 9, 1], d = 9
        Output: [3, 9, 1, 7]
        Explanation: 9 % 4 = 1 → rotate by 1 step.

-------------------------------------------------------------------------------
*/

class Solution {
public:
    // Helper function to reverse array portion
    void reversePart(vector<int>& arr, int start, int end) {
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    // Main function to rotate array left by d steps
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;  // handle cases where d > n

        // Step 1: Reverse first d elements
        reversePart(arr, 0, d - 1);

        // Step 2: Reverse remaining n - d elements
        reversePart(arr, d, n - 1);

        // Step 3: Reverse entire array
        reversePart(arr, 0, n - 1);
    }
};

int main() {
    int n, d;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter rotation value d: ";
    cin >> d;

    Solution obj;
    obj.rotateArr(arr, d);

    cout << "Array after left rotation: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
