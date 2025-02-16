class Solution:
    def constructDistancedSequence(self, n: int) -> List[int]:
        ans = [0] * (2*n - 1)
        vis = [0] * (n + 1)
        self.calc(0, ans, vis, n)
        return ans 
    
    def calc(self, i, ans, vis, n):
        if i == len(ans):
            return True
        if ans[i]: return self.calc(i + 1, ans, vis, n)

        for j in range(n, 0, -1):
            if vis[j]: continue 

            vis[j] = 1 
            ans[i] = j 
            
            if j == 1:
                if self.calc(i + 1, ans, vis, n):
                    return True 
            elif i + j < 2*n - 1 and ans[i + j] == 0:
                ans[i + j] = j 
                if self.calc(i + 1, ans, vis, n):
                    return True 
                ans[i + j] = 0
            vis[j] = ans[i] = 0 
            
        return False 