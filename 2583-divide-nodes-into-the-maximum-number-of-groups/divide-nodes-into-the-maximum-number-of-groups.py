from collections import deque
class Solution:
    def magnificentSets(self, n: int, e: List[List[int]]) -> int:
        adj = [[] for _ in range(n + 1)]
        for u, v in e:
            adj[u].append(v)
            adj[v].append(u)

        vis = [0] * (n + 1)
        nodes = []
        def dfs(u):
            nodes.append(u)
            vis[u] = True 
            for v in adj[u]:
                if not vis[v]:
                    dfs(v)

        def tryBFS(s: int) -> int:
            q = deque()
            q.append(s)
            dist = [-1] * (n + 1)
            dist[s] = 1 
            while len(q):
                u = q.popleft()
                for v in adj[u]:
                    if dist[v] == -1:
                        dist[v] = dist[u] + 1
                        q.append(v)
                    else:
                        if dist[v] != dist[u] - 1 and dist[v] != dist[u] + 1:
                            # print(s, u, v)
                            return 0
            return max(dist)

        ans = 0
        for i in range(1, n + 1):
            if not vis[i]:
                nodes = []
                dfs(i)
                # print(nodes)
                cr = 0
                for u in nodes:
                    cr = max(cr, tryBFS(u))
                if cr == 0: return -1 
                ans += cr
        
        return ans