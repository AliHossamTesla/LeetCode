from typing import List
from collections import deque

class DSU:
    def __init__(self, n: int, m: int):
        self.n = n  # Number of rows
        self.m = m  # Number of columns
        self.total_nodes = n * m  # Total number of nodes in the grid
        self.parent = [i for i in range(self.total_nodes)]  # Each node is its own parent initially
        self.rank = [1] * self.total_nodes  # Each node has rank 1 initially
        self.size = [1] * self.total_nodes  # Each set initially contains 1 element

    # Convert 2D coordinates (x, y) to 1D index
    def transfer(self, x: int, y: int) -> int:
        return x * self.m + y

    # Convert 1D index back to 2D coordinates (x, y)
    def inverse_transfer(self, i: int) -> List[int]:
        return [i // self.m, i % self.m]

    # Find the root of the set containing (x, y)
    def find(self, x: int, y: int) -> int:
        index = self.transfer(x, y)
        if self.parent[index] != index:
            # Path compression
            self.parent[index] = self.find(*self.inverse_transfer(self.parent[index]))
        return self.parent[index]

    # Union two sets containing (x1, y1) and (x2, y2)
    def union(self, x1: int, y1: int, x2: int, y2: int) -> bool:
        root_x = self.find(x1, y1)
        root_y = self.find(x2, y2)

        if root_x == root_y:
            return False  # Already in the same group (cycle detected)

        # Union by rank
        if self.rank[root_x] < self.rank[root_y]:
            self.parent[root_x] = root_y
            self.size[root_y] += self.size[root_x]  # Update the size of the set
        elif self.rank[root_x] > self.rank[root_y]:
            self.parent[root_y] = root_x
            self.size[root_x] += self.size[root_y]  # Update the size of the set
        else:
            self.parent[root_y] = root_x
            self.rank[root_x] += 1
            self.size[root_x] += self.size[root_y]  # Update the size of the set

        return True  # Successfully merged

    # Get the size of the set containing (x, y)
    def get_size(self, x: int, y: int) -> int:
        root = self.find(x, y)
        return self.size[root]


class Solution:
    def __init__(self):
        self.directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]

    def largestIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        dsu = DSU(n, m)
        visited = [[False for _ in range(m)] for _ in range(n)]
        ans = 0

        # Step 1: Perform floodfill to union all connected 1s
        for i in range(n):
            for j in range(m):
                if not visited[i][j] and grid[i][j] == 1:
                    self.floodfill(i, j, grid, visited, dsu, n, m)
                    ans = max(ans, dsu.get_size(i, j))  # Update the largest island size

        # Step 2: Try flipping each 0 to 1 and calculate the new island size
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 0:
                    unique_roots = set()
                    cr = 1  # Start with the flipped cell
                    for dir_ in self.directions:
                        di = i + dir_[0]
                        dj = j + dir_[1]
                        if 0 <= di < n and 0 <= dj < m and grid[di][dj] == 1:
                            root = dsu.find(di, dj)
                            if root not in unique_roots:  # Avoid double-counting
                                unique_roots.add(root)
                                cr += dsu.get_size(di, dj)
                    ans = max(ans, cr)  # Update the largest island size

        return ans

    def floodfill(self, x: int, y: int, grid: List[List[int]], visited: List[List[bool]], dsu: DSU, n: int, m: int):
        queue = deque()
        queue.append((x, y))
        visited[x][y] = True

        while queue:
            cx, cy = queue.popleft()
            for dir_ in self.directions:
                dx = cx + dir_[0]
                dy = cy + dir_[1]
                if 0 <= dx < n and 0 <= dy < m and grid[dx][dy] == 1 and not visited[dx][dy]:
                    dsu.union(cx, cy, dx, dy)  # Union the current cell with its neighbor
                    visited[dx][dy] = True  # Mark as visited
                    queue.append((dx, dy))