class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 3) {
            return n == 1 ? 1 : n - 1;
        }

        int l = 1, r = (n / 2) + 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            long long coins = (mid * (mid + 1LL)) / 2;
            if (coins <= n) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l - 1;
    }
};