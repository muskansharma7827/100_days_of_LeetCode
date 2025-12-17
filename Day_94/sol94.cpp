#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        ans.reserve(n);  
        for (int i = 1; i <= n; ++i) {
            string s;
            if (i % 3 == 0) s += "Fizz";
            if (i % 5 == 0) s += "Buzz";
            if (s.empty()) s = to_string(i);
            ans.push_back(s);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 15; 
    vector<string> result = sol.fizzBuzz(n);

    for (auto &s : result) {
        cout << s << "\n";
    }
    return 0;
}