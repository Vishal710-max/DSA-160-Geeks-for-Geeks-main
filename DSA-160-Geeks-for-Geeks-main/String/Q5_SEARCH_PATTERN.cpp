#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    --------------------------- SEARCH PATTERN (KMP) ---------------------------

    Given two strings:
        txt -> the main text
        pat -> pattern string

    Task:
        Return ALL starting indices (0-based) where 'pat' occurs in 'txt'.

    Constraints:
        • 1 ≤ txt.size() ≤ 10^6
        • 1 ≤ pat.size() ≤ txt.size()
        • Lowercase English letters only

    Why KMP?
        Naive search is O(n*m) → TLE
        KMP is O(n+m) → perfect for 10^6 constraints

    Steps:
        1. Build LPS (longest prefix-suffix) array for pattern
        2. Traverse text using LPS to skip unnecessary comparisons
*/

// --------------------------------------------------
// Build LPS Array (Longest Prefix Suffix)
// --------------------------------------------------
vector<int> buildLPS(string &pat) {
    int m = pat.size();
    vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// --------------------------------------------------
// KMP Search
// --------------------------------------------------
vector<int> KMPSearch(string &pat, string &txt) {
    vector<int> result;

    int n = txt.size();
    int m = pat.size();

    vector<int> lps = buildLPS(pat);

    int i = 0;  // index for txt
    int j = 0;  // index for pat

    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
        }

        if (j == m) {
            result.push_back(i - m); // found pattern at i-m
            j = lps[j - 1];
        }
        else if (i < n && txt[i] != pat[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return result;
}

// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------
int main() {
    string txt, pat;

    cout << "Enter text string: ";
    cin >> txt;

    cout << "Enter pattern string: ";
    cin >> pat;

    vector<int> ans = KMPSearch(pat, txt);

    if (ans.empty()) {
        cout << "No occurrence found." << endl;
    } else {
        cout << "Pattern found at indices: ";
        for (int idx : ans)
            cout << idx << " ";
        cout << endl;
    }

    return 0;
}
