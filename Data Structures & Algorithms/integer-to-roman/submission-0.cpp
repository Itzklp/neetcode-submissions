class Solution {
   public:
    string intToRoman(int num) {
        vector<pair<int, string>> mp = {{1, "I"},   {5, "V"},    {10, "X"},  {50, "L"}, {100, "C"},
                                        {500, "D"}, {1000, "M"}, {4, "IV"},  {9, "IX"}, {40, "XL"},
                                        {90, "XC"}, {400, "CD"}, {900, "CM"}};

        sort(mp.rbegin(), mp.rend());

        string ans = "";
        int n = mp.size();

        for (int i = 0; i < n; i++) {
            while (num >= mp[i].first) {
                ans += mp[i].second;
                num -= mp[i].first;
            }
        }

        return ans;
    }
};