#include <iostream>
using namespace std;

/*
    --------------------- Strings Rotations of Each Other ---------------------

    You are given two strings s1 and s2 of equal length.
    Check if s2 is a ROTATED VERSION of s1.

    A string is a rotation of another if:
        It can be formed by moving some characters from the front to the back
        OR from the back to the front.

    Example:
        s1 = "abcd", s2 = "cdab" → true
        s1 = "aab",  s2 = "aba"  → true
        s1 = "abcd", s2 = "acbd" → false

    Approach (Most Efficient):
        • If lengths differ → false
        • Create s1 + s1
        • If s2 is a substring of (s1 + s1) → rotation

    Why this works?
        Because every possible rotation of s1 appears inside s1+s1.

    Time Complexity: O(n)
*/

class Solution {
public:
    bool areRotations(string &s1, string &s2) {
        if (s1.length() != s2.length())
            return false;

        string doubled = s1 + s1;

        // If s2 appears inside s1+s1 → it's a rotation
        return doubled.find(s2) != string::npos;
    }
};

// ------------------------------- MAIN FUNCTION -------------------------------

int main() {
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    Solution obj;
    bool ans = obj.areRotations(s1, s2);

    if (ans)
        cout << "Strings ARE rotations of each other.\n";
    else
        cout << "Strings are NOT rotations.\n";

    return 0;
}
