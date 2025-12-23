#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int upperCount = 0;
        for (int i = 0; i < word.size(); i++) {
            if (isupper(word[i])) {
                upperCount++;
            }
        }
        if (upperCount == word.size()) return true;
        if (upperCount == 0) return true;
        if (upperCount == 1 && isupper(word[0])) return true;
        return false;
    }
};

int main() {
    Solution sol;
    vector<string> testWords = {"USA", "leetcode", "Google", "FlaG"};
    for (string word : testWords) {
        bool result = sol.detectCapitalUse(word);
        cout << word << " -> " << (result ? "Valid" : "Invalid") << endl;
    }
    return 0;
}