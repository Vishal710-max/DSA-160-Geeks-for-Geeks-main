#include <iostream>
#include <vector>
using namespace std;

/*
    ------------------------ Min Chars to Add for Palindrome ------------------------

    Given a string s, find the MINIMUM characters to add at the FRONT
    to make the string a palindrome.

    Examples:
        s = "abc" → output = 2
        s = "aacecaaa" → output = 2

    Optimal Approach (KMP + LPS):
        • Build string:  temp = s + '#' + reverse(s)
        • Compute LPS array of temp
        • LPS[last] gives length of the longest palindromic prefix
        • Answer = s.length() - LPS[last]

    Why this works?
        Because LPS captures the longest prefix of s that is also a suffix of reverse(s),
        which means it's the largest prefix that forms a palindrome.

    Complexity:
        Time: O(n)
        Space: O(n)
*/

// Build LPS array for KMP
vector<int> computeLPS(string &str) {
    int n = str.size();
    vector<int> lps(n, 0);

    int len = 0;   // length of previous LPS
    int i = 1;

    while (i < n) {
        if (str[i] == str[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

class Solution {
public:
    int minChar(string &s) {

        string rev = string(s.rbegin(), s.rend());

        // s + '#' + reverse(s)
        string temp = s + "#" + rev;

        vector<int> lps = computeLPS(temp);

        // LPS last value = longest palindromic prefix
        int longestPalPrefix = lps.back();

        // Min chars = total length - palindromic prefix length
        return s.length() - longestPalPrefix;
    }
};

// ------------------------------ MAIN FUNCTION ------------------------------

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    Solution obj;

    int ans = obj.minChar(s);

    cout << "Minimum characters to add = " << ans << endl;

    return 0;
}
