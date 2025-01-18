import heapq
class Solution:
    def minCost(self, g: List[List[int]]) -> int:
        q = []
        n, m = len(g), len(g[0])
        dist = [[float('inf') for _ in range(m)] for _ in range(n)]
        dist[0][0] = 0 
        heapq.heappush(q, (0, 0, 0))  # Push (cost, row, col) into the heap

        # Directions corresponding to the grid values
        directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        
        while q:
            cost, x, y = heapq.heappop(q)
            if x == n - 1 and y == m - 1:
                return cost 
            
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m:
                    new_cost = cost + (1 if (dx, dy) != (directions[g[x][y] - 1]) else 0)
                    if new_cost < dist[nx][ny]: 
                        dist[nx][ny] = new_cost
                        heapq.heappush(q, (new_cost, nx, ny))
        
        return -1 