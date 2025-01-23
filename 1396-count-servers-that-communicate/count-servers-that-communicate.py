class Solution:
    def countServers(self, g: List[List[int]]) -> int:
        n, m = len(g), len(g[0])
        rw, clm = [0] * n, [0] * m
        for i in range(n):
            for j in range(m):
                if g[i][j]:
                    rw[i] += 1
                    clm[j] += 1
        
        ans = 0 
        for i in range(n):
            for j in range(m):
                if g[i][j] and (clm[j] > 1 or rw[i] > 1):
                    ans += 1

        return ans 