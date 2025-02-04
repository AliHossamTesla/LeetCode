class Solution:
    def maxAscendingSum(self, a: List[int]) -> int:
        ans = cr = a[0]
        for i in range(1, len(a)):
            if a[i]  > a[i - 1]:
                cr += a[i]
            else: cr = a[i]
            ans = max(ans, cr)
        return ans 