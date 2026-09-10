class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int n = digits.size();

        digits[n - 1]++;
        for (int i = n - 1; i >= 0; i--) {
            int sum = carry + digits[i];
            carry = sum / 10;
            digits[i] = sum % 10;
        }

        if (carry != 0) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};
