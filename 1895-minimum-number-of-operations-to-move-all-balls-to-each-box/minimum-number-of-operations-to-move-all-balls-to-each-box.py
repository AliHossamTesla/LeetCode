class Solution:
    def minOperations(self, a: str) -> List[int]:
        lcnt, rcnt = 0, 0
        lsum, rsum = 0, 0

        for i in range(len(a) - 1, -1, -1):
            rsum += rcnt 
            rcnt += 1 if a[i] == '1' else 0

        ans = []
        for i in range(len(a)):
            ans.append(rsum + lsum)
            lcnt += 1 if a[i] == '1' else 0
            lsum += lcnt 
            rcnt -= 1 if a[i] == '1' else 0
            rsum -= rcnt 
        
        return ans 
        