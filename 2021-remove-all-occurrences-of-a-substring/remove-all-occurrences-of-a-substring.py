class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        n, m = len(s), len(part)
        part = part + '#' + s
        pi = [0]
        ans = []
        for i in range(1, len(part)):
            j = pi[-1]
            while j > 0 and part[i] != part[j]:
                j = pi[j - 1]
            if part[i] == part[j]: 
                j += 1

            pi.append(j)
            if i > m:
                ans.append(part[i])
                if pi[-1] == m:
                    ans = ans[:-m]
                    pi = pi[:-m]
        
        return ''.join(ans)
