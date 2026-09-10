class TimeMap {
   public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {}

    void set(string key, string value, int timestamp) { mp[key].push_back({timestamp, value}); }

    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) {
            return "";
        }

        int low = 0, high = mp[key].size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mp[key][mid].first <= timestamp) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (high == -1) {
            return "";
        }

        return mp[key][high].second;
    }
};
