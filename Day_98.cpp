#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }

        vector<int> state(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (hasCycle(adj, state, i)) return false;
        }
        return true;
    }
private:
    bool hasCycle(vector<vector<int>>& adj, vector<int>& state, int node) {
        if (state[node] == 1) return true;
        if (state[node] == 2) return false;

        state[node] = 1;
        for (int neighbor : adj[node]) {
            if (hasCycle(adj, state, neighbor)) return true;
        }
        state[node] = 2;
        return false;
    }
};

int main() {
    Solution sol;

    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    bool result = sol.canFinish(numCourses, prerequisites);
    cout << (result ? "All courses can be finished" : "Cannot finish all courses") << endl;

    return 0;
}