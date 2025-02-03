class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        dec, inc, ans = [1] * 3
        for i in range(1, len(nums)):
            if nums[i] > nums[i - 1]:
                inc += 1
                dec = 1
            elif nums[i] < nums[i - 1]:
                dec += 1
                inc = 1
            else:
                dec = inc = 1
            ans = max(ans, dec, inc)
        return ans 