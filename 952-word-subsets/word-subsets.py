class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        cnt = [0] * 26 

        def freQ(s):
            tcnt = [0] * 26 
            for i in s:
                tcnt[ord(i) - ord('a')] += 1
            return tcnt 

        for s in words2:
            cnt = [max(i, j) for i, j in zip(cnt, freQ(s))] 
        
        ans = [] 
        for s in words1:
            tcnt = freQ(s)
            if sum(1 for i in range(26) if tcnt[i] >= cnt[i]) == 26:
                ans.append(s)
        
        return ans 
