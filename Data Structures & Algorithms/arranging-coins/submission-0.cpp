class Solution {
   public:
    int arrangeCoins(int n) {
        int totalComplete = 0;

        int rem = n;
        int k = 1;

        while (rem >= k) {
            totalComplete++;
            rem -= k;
            k++;
        }

        return totalComplete;
    }
};