class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& time : times) {
            adj[time[0]].push_back({time[2], time[1]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(n + 1, INT_MAX);
        distance[k] = 0;
        pq.push({0, k});

        int maxTime = 0;

        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();

            if (dist > distance[node]) {
                continue;
            }

            for (auto& [d, n] : adj[node]) {
                if (distance[n] > d + distance[node]) {
                    distance[n] = d + distance[node];
                    pq.push({distance[n], n});
                }
            }
        }

        int minTime = 0;

        for (int i = 1; i <= n; i++) {
            if (distance[i] == INT_MAX) {
                return -1;
            }

            minTime = max(minTime, distance[i]);
        }

        return minTime;
    }
};
