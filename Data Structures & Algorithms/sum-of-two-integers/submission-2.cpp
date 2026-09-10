class Solution {
public:
    int getSum(int a, int b) {
        uint32_t x = static_cast<uint32_t>(a);
        uint32_t y = static_cast<uint32_t>(b);

        uint32_t ans = 0;
        uint32_t carry = 0;

        for (int i = 0; i < 32; i++) {
            uint32_t val1 = (x >> i) & 1u;
            uint32_t val2 = (y >> i) & 1u;

            uint32_t curr = val1 ^ val2 ^ carry;

            carry = (val1 + val2 + carry) >= 2;

            if (curr) {
                ans |= (1u << i);
            }
        }

        return static_cast<int>(ans);
    }
};