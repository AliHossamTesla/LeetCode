class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        rsum = sum(nums)
        lsum, ans = 0, 0

        for i in nums[:-1]:
            lsum += i 
            rsum -= i 
            if lsum >= rsum:
                ans += 1 
        
        return ans