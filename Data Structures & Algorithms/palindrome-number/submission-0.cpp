class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int tmp = 0;
        int tx = x;

        while (tx > 0) {
            tmp = tmp * 10 + (tx % 10);
            tx /= 10;
        }

        return tmp == x;
    }
};