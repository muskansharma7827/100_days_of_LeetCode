#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int start = 0;
        int end = 0;
        int idx = 0;
        while (idx < n) {
            while (idx < n && s[idx] == ' ')
                idx++;
            if (idx == n)
                break;
            while (idx < n && s[idx] != ' ') {
                s[end++] = s[idx++];
            }
            reverse(s.begin() + start, s.begin() + end);
            s[end++] = ' ';
            start = end;
            idx++;
        }
        s.resize(end - 1);
        return s;
    }
};

int main() {
    Solution sol;
    string s = "  the sky is blue  ";
    string result = sol.reverseWords(s);
    cout << "Reversed words: \"" << result << "\"" << endl;
    return 0;
}