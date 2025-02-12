class Solution:
    def maximumSum(self, nums: List[int]) -> int:
        def helper(i):
            cr = 0 
            while i:
                cr += (i % 10)
                i //= 10 
            return cr 
        
        mx = [0] * 100
        ans = -1 
        for i in nums:
            sm = helper(i)
            if mx[sm] != 0: ans = max(ans, mx[sm] + i)
            mx[sm] = max(mx[sm], i)
        return ans 