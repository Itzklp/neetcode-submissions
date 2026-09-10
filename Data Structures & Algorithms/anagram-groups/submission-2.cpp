class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string& s : strs) {
            vector<int> count(26, 0);

            for (char c : s) {
                count[c - 'a']++;
            }

            string key = to_string(count[0]);

            for (int i = 1; i < 26; i++) {
                key += ',' + to_string(count[i]);
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;

        for (auto& [key, value] : mp) {
            ans.push_back(value);
        }

        return ans;
    }
};
