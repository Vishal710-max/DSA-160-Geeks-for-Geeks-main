#include <iostream>
using namespace std;

class Solution {
public:

    /*
        ----------------------------- Add Binary Strings -----------------------------

        Given two binary strings s1 and s2 (containing only '0' and '1'),
        return the resulting binary string after adding them.

        Notes:
            • Input may contain leading zeros.
            • Output must NOT have leading zeros (except for "0").
            • Length can be as large as 10^6 → must use O(n) solution.

        Example 1:
            s1 = "1101", s2 = "111"
            Output = "10100"

        Example 2:
            s1 = "00100", s2 = "010"
            Output = "110"

        Approach:
            • Two pointers from the end of both strings.
            • Add digits + carry, produce new bit.
            • Append result in reverse order.
            • Reverse at the end and remove leading zeros.

        Complexity:
            Time:  O(n)
            Space: O(n) (result string)
    */

    string addBinary(string& s1, string& s2) {

        int i = s1.size() - 1;
        int j = s2.size() - 1;

        int carry = 0;
        string res = "";

        // Loop through both strings
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += (s1[i] - '0');
            if (j >= 0) sum += (s2[j] - '0');

            res.push_back(char(sum % 2 + '0'));  // store current bit
            carry = sum / 2;

            i--;
            j--;
        }

        // Reverse result
        reverse(res.begin(), res.end());

        // Remove leading zeros unless result is exactly "0"
        int pos = 0;
        while (pos < res.size()-1 && res[pos] == '0') pos++;

        return res.substr(pos);
    }
};
