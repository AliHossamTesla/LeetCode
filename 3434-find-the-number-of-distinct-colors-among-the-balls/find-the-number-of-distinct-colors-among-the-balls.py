class Solution:
    def queryResults(self, limit: int, q: List[List[int]]) -> List[int]:
        ans = []
        col, freq = defaultdict(int), defaultdict(int)
        cur = 0
        
        for x, y in q:
            prev = col[x]

            if prev != 0:
                freq[prev] -= 1
                if freq[prev] == 0:
                    del freq[prev]
                    cur -= 1
            
            if freq[y] == 0:
                cur += 1
            
            freq[y] += 1
            col[x] = y 

            ans.append(cur)
        
        return ans 