class Solution:
    def firstCompleteIndex(self, a: List[int], mat: List[List[int]]) -> int:
        n, m = len(mat), len(mat[0])
        R, C = [m] * n, [n] * m
        idx = [None] * (n * m + 1)
        for i in range(n):
            for j in range(m):
                idx[mat[i][j]] = (i, j)
        
        for i in range(len(a)):
            x, y = idx[a[i]]
            R[x] -= 1
            C[y] -= 1
            if R[x] == 0 or C[y] == 0:
                return i 
        
        return -1 