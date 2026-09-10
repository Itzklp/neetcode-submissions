class Solution {
   public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freqMap;

        for (char& ch : s) {
            freqMap[ch]++;
        }

        for (char& ch : t) {
            freqMap[ch]--;
        }

        for (auto& it : freqMap) {
            if (it.second != 0) {
                return false;
            }
        }

        return true;
    }
};
