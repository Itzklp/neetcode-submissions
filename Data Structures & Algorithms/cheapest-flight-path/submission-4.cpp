class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto &flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        const int INF = 1e9;
        vector<int> dist(n, INF);

        dist[src] = 0;

        queue<int> q;
        q.push(src);

        int stops = 0;

        while (!q.empty() && stops <= k) {

            int size = q.size();

            vector<int> temp = dist;

            while (size--) {

                int node = q.front();
                q.pop();

                for (auto &[next, price] : adj[node]) {

                    if (dist[node] + price < temp[next]) {

                        temp[next] = dist[node] + price;

                        q.push(next);
                    }
                }
            }

            dist = temp;
            stops++;
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};