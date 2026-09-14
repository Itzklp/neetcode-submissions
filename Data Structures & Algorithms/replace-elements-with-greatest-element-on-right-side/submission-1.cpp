class Solution {
   public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();

        vector<int> ans(n, -1);
        int maxEle = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            ans[i] = maxEle;
            maxEle = max(maxEle, arr[i]);
        }

        return ans;
    }
};