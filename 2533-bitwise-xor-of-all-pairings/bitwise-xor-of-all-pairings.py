class Solution:
    def xorAllNums(self, a: List[int], b: List[int]) -> int:
        xr = 0 
        if len(b) % 2 == 1:
            for i in a:
                xr ^= i
        
        if len(a) % 2 == 1:
            for i in b:
                xr ^= i
        
        return xr 