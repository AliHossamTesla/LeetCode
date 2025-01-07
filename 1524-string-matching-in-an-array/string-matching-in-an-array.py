class Solution:
    def stringMatching(self, w: List[str]) -> List[str]:
        ans = [] 

        def is_sub(s, t):
            if len(s) > len(t):
                return False
            for i in range(len(t) - len(s) + 1):
                if s == t[i:i + len(s)]:
                    return True
            return False

        for i in range(len(w)):
            for j in range(len(w)):
                if i != j and is_sub(w[i], w[j]):
                    ans.append(w[i])
                    break

        return ans 