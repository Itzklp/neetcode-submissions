class Solution {
   public:
    bool dfs(vector<vector<int>>& adj, int i, vector<int>& state, stack<int>& st) {
        state[i] = 1;

        for (auto& nei : adj[i]) {
            if (state[nei] == 1) {
                return true;
            }

            if (state[nei] == 0) {
                if (dfs(adj, nei, state, st)) {
                    return true;
                }
            }
        }

        st.push(i);
        state[i] = 2;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> state(numCourses, 0);
        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (dfs(adj, i, state, st)) {
                    return {};
                }
            }
        }

        vector<int> ans(st.size());

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
