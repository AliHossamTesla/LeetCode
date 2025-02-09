from typing import List

class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        n = len(nums)
        a = [nums[i] - i for i in range(n)]
        freq = {}
        
        # Count the frequency of each element in `a`
        for i in a:
            freq[i] = freq.get(i, 0) + 1
        
        # Calculate the total number of pairs
        total_pairs = n * (n - 1) // 2
        
        # Calculate the number of good pairs
        good_pairs = 0
        for v in freq.values():
            good_pairs += v * (v - 1) // 2
        
        # Bad pairs = Total pairs - Good pairs
        bad_pairs = total_pairs - good_pairs
        
        return bad_pairs