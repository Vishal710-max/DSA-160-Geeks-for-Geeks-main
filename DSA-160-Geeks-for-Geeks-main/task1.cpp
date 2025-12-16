#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int last = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                arr[last] = arr[i];
                last++;
            }
        }
        for (int j = last; j < arr.size(); j++) {
            arr[j] = 0;
        }
    }
};

int main() {
    // Example usage
    vector<int> arr = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0};
    
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    Solution obj;
    obj.pushZerosToEnd(arr);

    cout << "After pushing zeros to end: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
