class Solution:
    def countPrefixSuffixPairs(self, w: List[str]) -> int:
        ans = 0 

        for i in range(len(w)):
            for j in range(i + 1, len(w)):
                if len(w[i]) <= len(w[j]):
                    # print(w[i], w[j][:len(w[i])], w[j][:-len(w[i])])
                    if w[j].startswith(w[i]) and w[j].endswith(w[i]):
                        ans += 1
        
        return ans 
