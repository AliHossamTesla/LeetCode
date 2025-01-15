class Solution:
    def minimizeXor(self, num1: int, num2: int) -> int:
        cnt, ans = num2.bit_count(), 0
        for i in range(30, -1, -1):
            if num1 >> i & 1 and cnt:
                ans |= (1 << i)
                cnt -= 1
        
        for i in range(31):
            if not (ans >> i & 1) and cnt:
                ans |= (1 << i)
                cnt -= 1
        return ans 