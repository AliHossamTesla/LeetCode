class Solution:
    def check(self, nums: List[int]) -> bool:
        n = len(nums)
        for i in range(n):
            ok = True
            for j in range(1, n):
                if nums[(j + i) % n] < nums[(j + i - 1 + n) % n]:
                    ok = False 
                    break 
            if ok:
                return True
            
        return False 

