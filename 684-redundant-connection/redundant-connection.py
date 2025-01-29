from typing import List

class Solution:
    def findRedundantConnection(self, e: List[List[int]]) -> List[int]:
        d = DSU(len(e) + 1)  
        for u, v in e:
            if not d.union(u, v):  
                return [u, v] 
        return [-1, -1]

class DSU:
    def __init__(self, n):
        """
        Initialize the DSU data structure with `n` elements.
        Each element is initially its own parent, and the rank is 1.
        """
        self.parent = list(range(n))  # Each element is its own parent initially
        self.rank = [1] * n  # Rank is used for union by rank

    def find(self, x):
        """
        Find the root of the set containing `x` with path compression.
        Path compression flattens the tree, making future queries faster.
        """
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # Path compression
        return self.parent[x]

    def union(self, x, y):
        """
        Union the sets containing `x` and `y` using union by rank.
        Union by rank attaches the shorter tree under the root of the taller tree.
        """
        root_x = self.find(x)
        root_y = self.find(y)

        if root_x == root_y:
            return False  # Already in the same set (cycle detected)

        # Union by rank
        if self.rank[root_x] < self.rank[root_y]:
            self.parent[root_x] = root_y
        elif self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x
        else:
            self.parent[root_y] = root_x
            self.rank[root_x] += 1

        return True  # Successfully merged

    def is_connected(self, x, y):
        """
        Check if `x` and `y` are in the same set.
        """
        return self.find(x) == self.find(y)