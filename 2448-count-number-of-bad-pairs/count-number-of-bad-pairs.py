from typing import List

class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n = len(nums)
        a = [v - i for i, v in enumerate(nums)]
        cnt = Counter(a)

        total_pairs = n * (n - 1) // 2
        for v in cnt.values():
            total_pairs -= v * (v - 1) // 2
        
        return total_pairs