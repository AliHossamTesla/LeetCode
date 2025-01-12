class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        if len(s) % 2 == 1:
            return False
        r, a = 0, 0 
        for c, i in zip(s, locked):
            # print(c, i)
            if i == "0":
                a += 1
            else:
                if c == '(':
                    r += 1 
                else:
                    if r > 0:
                        r -= 1
                    elif a > 0:
                        a -= 1
                    else: return False
        
        s = s[::-1]
        locked = locked[::-1]
        print(s, locked)
        r, a = 0, 0 
        for c, i in zip(s, locked):
            if i == "0":
                a += 1
            else:
                if c == ')':
                    r += 1 
                else:
                    if r > 0:
                        r -= 1
                    elif a > 0:
                        a -= 1
                    else: return False
        
        return True