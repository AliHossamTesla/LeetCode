class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        n = len(A)
        cnta, cntb = [0] * (n + 1), [0] * (n + 1)
        C = []
        for a, b in zip(A, B):
            if a == b:
                C.append(C[-1] + 1 if len(C) else 1)
            else:
                cnta[a] += 1
                cntb[b] += 1 
                if cntb[a] and cnta[b]:
                    C.append(C[-1] + 2)
                elif cnta[b] or cntb[a]:
                    C.append(C[-1] + 1)
                else:
                    C.append(C[-1] if len(C) else 0)
        
        return C