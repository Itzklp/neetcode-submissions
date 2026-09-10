class Solution {
   public:
    bool dfs(vector<vector<int>>& adj, int i, vector<int>& state) {
        state[i] = 1;

        for (auto nei : adj[i]) {
            if (state[nei] == 1) {
                return true;
            }

            if (state[nei] == 0) {
                if (dfs(adj, nei, state)) return true;
            }
        }

        state[i] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (dfs(adj, i, state)) {
                    return false;
                }
            }
        }

        return true;
    }
};
