class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        cnt = [1, 0]
        pref, ans = 0, 0
        for i in arr:
            pref += i
            ans += cnt[pref & 1 ^ 1]
            cnt[pref & 1] += 1 
        return ans % 1_000_000_007