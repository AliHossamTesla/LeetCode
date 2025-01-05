class Solution:
    def shiftingLetters(self, s: str, shifts: List[List[int]]) -> str:
        tot = [0] * (len(s) + 1)
        for v in shifts:
            if v[2] == 1:
                tot[v[0]] += 1 
                tot[v[1] + 1] -= 1
            else:
                tot[v[0]] -= 1 
                tot[v[1] + 1] += 1
        
        s = list(s)
        s[0] = chr(ord('a') + ((ord(s[0]) - ord('a') + tot[0] + 26) % 26))
        for i in range(1, len(s)):
            tot[i] += tot[i - 1]
            s[i] = chr(ord('a') + ((ord(s[i]) - ord('a') + tot[i] + 26) % 26))
        
        return ''.join(s) 