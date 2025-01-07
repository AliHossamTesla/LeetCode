class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        ans = []
        for i, word in enumerate(words):
            for other in words:
                if word != other and word in other:
                    ans.append(word)
                    break
        return ans
