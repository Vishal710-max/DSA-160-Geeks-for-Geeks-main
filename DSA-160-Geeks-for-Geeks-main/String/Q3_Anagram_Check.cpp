#include <iostream>
using namespace std;

/* 
    ----------------------------- Anagram Check -----------------------------

    Given two strings s1 and s2 (both containing only lowercase English letters),
    determine whether they are anagrams of each other.

    Definition:
        Two strings are anagrams if:
            • They contain the SAME CHARACTERS
            • With the SAME FREQUENCY
            • Order does NOT matter

    Example 1:
        s1 = "geeks"
        s2 = "kseeg"
        Output: true

    Example 2:
        s1 = "allergy"
        s2 = "allergyy"
        Output: false

    Approach:
        • If lengths differ → not anagram.
        • Use a frequency array for 26 lowercase letters.
        • Count chars of s1, subtract chars of s2.
        • If all counts become zero → strings are anagrams.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    bool isAnagram(string s1, string s2) {

        if (s1.length() != s2.length())
            return false;

        int freq[26] = {0};

        for (char c : s1)
            freq[c - 'a']++;

        for (char c : s2)
            freq[c - 'a']--;

        for (int i = 0; i < 26; i++)
            if (freq[i] != 0)
                return false;

        return true;
    }
};

// --------------------------- MAIN FUNCTION ---------------------------

int main() {

    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    Solution obj;

    if (obj.isAnagram(s1, s2))
        cout << "Strings are Anagrams" << endl;
    else
        cout << "Strings are NOT Anagrams" << endl;

    return 0;
}

