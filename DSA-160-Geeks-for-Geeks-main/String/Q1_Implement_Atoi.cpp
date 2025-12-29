#include <iostream>
#include <string>
using namespace std;

/*
    ----------------------------- Implement Atoi -----------------------------

    Convert a string s into an integer WITHOUT using built-in functions.

    Rules:
    1. Ignore leading whitespaces.
    2. Take an optional sign ('+' or '-').
    3. Read digits until:
         - a non-digit is found, OR
         - string ends
    4. If no digits are present → return 0.
    5. Handle 32-bit integer overflow:
         If number >  2^31 - 1 → return  2147483647
         If number < -2^31     → return -2147483648

    Constraints:
        1 ≤ |s| ≤ 17

    Examples:
      s = "  -123"     → -123
      s = "   "        → 0
      s = "12312abc"   → 12312
      s = "-9999999999" → -2147483648 (overflow)
      s = "0012fg"     → 12

--------------------------------------------------------------------------- */

class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;      // use long long to detect overflow
        int i = 0, n = s.length();
        int sign = 1;

        // 1. Skip leading whitespaces
        while (i < n && s[i] == ' ')
            i++;

        // 2. Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }

        // 3. Read digits
        bool digitFound = false;

        while (i < n && isdigit(s[i])) {
            digitFound = true;
            int digit = s[i] - '0';

            ans = ans * 10 + digit;

            // 4. Handle overflow early
            if (sign == 1 && ans > INT_MAX)
                return INT_MAX;

            if (sign == -1 && -ans < INT_MIN)
                return INT_MIN;

            i++;
        }

        // 5. If no digit found → return 0
        if (!digitFound)
            return 0;

        return ans * sign;
    }
};

// --------------------------- MAIN FUNCTION ------------------------------

int main() {
    string s;
    cout << "Enter string: ";
    
    // Read full line including spaces
    getline(cin, s);

    Solution obj;
    cout << "Converted Integer = " << obj.myAtoi(s) << endl;

    return 0;
}
