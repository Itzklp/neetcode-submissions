class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        s = set()

        for i in nums:
            s.add(i)

        return len(s) != len(nums)
