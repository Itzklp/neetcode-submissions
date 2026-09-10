class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        d = defaultdict(int)

        for a in s:
            d[a] += 1

        for a in t:
            d[a] -= 1

        for k, v in d.items():
            if v != 0:
                return False

        return True
