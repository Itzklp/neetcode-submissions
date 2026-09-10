class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int profit = 0;
        int n = prices.size();

        for (int i = 0; i < n - 1; i++) {
            if (prices[buy] > prices[i]) {
                buy = i;
            }

            profit = max(profit, prices[i + 1] - prices[buy]);
        }

        return profit;
    }
};
