class Solution {
   public:
    bool isHappy(int n) {
        unordered_set<int> st;

        while (!st.count(n)) {
            st.insert(n);

            int tmp = n;
            int sum = 0;
            while (tmp > 0) {
                sum += (tmp % 10) * (tmp % 10);
                tmp /= 10;
            }

            n = sum;

            if (n == 1) {
                return true;
            }
        }

        return false;
    }
};
