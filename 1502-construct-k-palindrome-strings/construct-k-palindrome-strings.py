class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if len(s) < k:
            return False 
        
        cnt = [0] * 26 
        for i in s:
            cnt[ord(i) - ord('a')] += 1
        
        odd = 0
        for i in range(26):
            odd += cnt[i] % 2 
        
        return odd <= k