class DisjointSet {
    vector<int> size, parent;

   public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) {
            return;
        }

        if (size[pu] >= size[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        } else {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};

class Solution {
   public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DisjointSet ds(n);
        vector<vector<int>> edges;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({distance, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int cost = 0;

        for (auto& edge : edges) {
            if (ds.findParent(edge[1]) != ds.findParent(edge[2])) {
                cost += edge[0];
                ds.unionBySize(edge[1], edge[2]);
            }
        }

        return cost;
    }
};
