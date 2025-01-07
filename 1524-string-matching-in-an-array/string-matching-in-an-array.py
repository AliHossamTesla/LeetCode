class Solution:
    def stringMatching(self, w: List[str]) -> List[str]:
        t = ' '.join(w)
        ans = [i for i in w if t.count(i) > 1]
        return ans 