#include <iostream>
#include <string>
using namespace std;

/*
    --------------------------- Non-Repeating Character ---------------------------

    Given a string s consisting only of lowercase English letters,
    return the FIRST non-repeating character in s.

    If every character repeats, return '$'.

    Examples:
        Input: "geeksforgeeks"
        Output: 'f'
        Explanation: 'f' appears only once and is the first such character.

        Input: "racecar"
        Output: 'e'

        Input: "aabbccc"
        Output: '$'

    Constraints:
        1 ≤ s.size() ≤ 100000

    Approach:
        1. Build frequency array of size 26.
        2. Traverse string again:
            The first character whose freq == 1 is the answer.
        3. If none found → return '$'.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    char nonRepeatingChar(string &s) {

        int freq[26] = {0};

        // Count frequencies
        for (char c : s)
            freq[c - 'a']++;

        // Find the first character with frequency 1
        for (char c : s)
            if (freq[c - 'a'] == 1)
                return c;

        return '$';
    }
};

// ---------------------------- MAIN FUNCTION ----------------------------

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    Solution obj;

    char ans = obj.nonRepeatingChar(s);

    if (ans == '$')
        cout << "No non-repeating character found. Output: $" << endl;
    else
        cout << "First non-repeating character: " << ans << endl;

    return 0;
}
