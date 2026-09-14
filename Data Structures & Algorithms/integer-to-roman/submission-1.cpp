class Solution {
   public:
    string intToRoman(int num) {
        vector<pair<int, string>> mp = {
            {1, "I"},   {4, "IV"},  {5, "V"},    {9, "IX"},  {10, "X"},   {40, "XL"}, {50, "L"},
            {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};

        string ans = "";
        int n = mp.size();

        for (int i = n - 1; i >= 0; i--) {
            while (num >= mp[i].first) {
                ans += mp[i].second;
                num -= mp[i].first;
            }
        }

        return ans;
    }
};