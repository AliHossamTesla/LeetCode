class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        pref = list(accumulate(nums, initial=0))
        return max(pref) - min(pref)