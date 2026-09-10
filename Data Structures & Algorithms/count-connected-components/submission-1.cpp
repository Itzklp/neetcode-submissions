class DisjointSet {
    vector<int> parent, size;

   public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
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
    int countComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);

        for (auto& edge : edges) {
            ds.unionBySize(edge[0], edge[1]);
        }

        unordered_set<int> components;

        for (int i = 0; i < n; i++) {
            components.insert(ds.findParent(i));
        }

        return components.size();
    }
};