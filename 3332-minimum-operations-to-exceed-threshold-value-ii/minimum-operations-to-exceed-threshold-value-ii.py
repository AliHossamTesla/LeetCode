class Solution:
    def minOperations(self, q: List[int], k: int) -> int:
        heapq.heapify(q)
        
        ans = 0
        while len(q) > 1:
            a, b = heapq.heappop(q), heapq.heappop(q)
            mn, mx = min(a, b), max(a, b)
            if mn >= k: break 
            ans += 1
            heapq.heappush(q, 2*mn + mx)

        return ans 