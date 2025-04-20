class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lo, int hi) {
        vector<int> seen; // sorted vector
        long long ans = 0;

        for (int i : nums) {
            int l = lower_bound(seen.begin(), seen.end(), lo - i) - seen.begin();
            int r = upper_bound(seen.begin(), seen.end(), hi - i) - seen.begin();
            ans += r - l;
            seen.insert(upper_bound(seen.begin(), seen.end(), i), i); // keep sorted
        }

        return ans;
    }
};
