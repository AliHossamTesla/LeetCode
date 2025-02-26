class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        mn, mx = 0, 0
        pref, ans  = 0, 0
        for i in nums:
            pref += i
            crMx, crMn = max(pref, mx), min(pref, mn)
            ans = max(ans, crMx - mn, -1*(crMn - mx))
            mn, mx = crMn, crMx
        return ans