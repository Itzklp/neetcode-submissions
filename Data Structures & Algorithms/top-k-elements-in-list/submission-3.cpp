class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int i : nums) {
            mp[i]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& [ele, count] : mp) {
            bucket[count].push_back(ele);
        }

        vector<int> ans;

        for (int i = bucket.size() - 1; i >= 1 && ans.size() < k; i--) {
            for (int ele : bucket[i]) {
                ans.push_back(ele);

                if (ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};