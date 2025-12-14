#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int count[26] = {0};
        for (int i = 0; i < magazine.size(); i++) {
            count[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            if (count[ransomNote[i] - 'a'] == 0) {
                return false;
            }
            count[ransomNote[i] - 'a']--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string ransomNote = "aa";
    string magazine = "aab";

    if (sol.canConstruct(ransomNote, magazine)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}