#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        
        if (n == 2 || n == 3) {
            return true;
        }
        
        if (n % 2 == 0 || n % 3 == 0) {
            return false;
        }
        
        for (int i = 5; i <= sqrt(n); i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    Solution obj;
    if (obj.isPrime(n)) {
        cout << n << " is a prime number." << endl;
    } else {
        cout << n << " is not a prime number." << endl;
    }

    return 0;
}
