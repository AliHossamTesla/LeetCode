class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        l, r = min(nums), max(nums)
        while l <= r:
            md = (l + r)//2
            cnt = 0 
            i = 0
            while i < len(nums):
                if nums[i] <= md:
                    cnt += 1
                    i += 1
                i += 1
            if cnt >= k:
                r = md - 1
            else:
                l = md + 1
        return l 