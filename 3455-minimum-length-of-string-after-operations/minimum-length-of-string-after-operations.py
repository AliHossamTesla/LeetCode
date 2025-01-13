class Solution:
    def minimumLength(self, s: str) -> int:
        cnt = [s.count(chr(ord('a') + i)) for i in range(26)]
        ans = 0 
        for i in cnt:
            if i > 0:
                ans += 1 if i % 2 != 0 else 2
        return ans 