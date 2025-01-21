class Solution:
    def gridGame(self, g: List[List[int]]) -> int:
        ans = float('inf')
        pref, suf = 0, sum(g[0])
        for i in range(len(g[0])):
            suf -= g[0][i]
            ans = min(ans, max(suf, pref))
            pref += g[1][i] 
        return ans