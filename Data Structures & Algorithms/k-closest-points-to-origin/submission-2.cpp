class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<int, int, int>> pq;

        for (auto& point : points) {
            int x = (point[0] - 0) * (point[0] - 0);
            int y = (point[1] - 0) * (point[1] - 0);

            int distance = x + y;

            pq.push({distance, point[0], point[1]});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {
            auto [d, x, y] = pq.top();
            pq.pop();

            ans.push_back({x, y});
        }

        return ans;
    }
};
