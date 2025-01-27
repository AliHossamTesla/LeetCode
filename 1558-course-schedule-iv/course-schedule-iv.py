class Solution:
    def checkIfPrerequisite(self, n: int, p: List[List[int]], q: List[List[int]]) -> List[bool]:
        reachable = [[False for _ in range(n)] for _ in range(n)]
        adj = [[] for _ in range(n)]
        for u, v in p:
            adj[u].append(v)
        
         # Perform BFS for each node to find all reachable nodes
        for i in range(n):
            queue = deque([i])
            while queue:
                u = queue.popleft()
                for v in adj[u]:
                    if not reachable[i][v]:
                        reachable[i][v] = True
                        queue.append(v)
        
        # Answer the queries
        ans = []
        for u, v in q:
            ans.append(reachable[u][v])
        return ans


