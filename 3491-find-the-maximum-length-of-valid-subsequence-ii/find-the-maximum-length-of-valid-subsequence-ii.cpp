class Solution {
public:
    int maximumLength(vector<int>& a, int k) {
        int n = a.size(), ans = 0;
        vector<vector<int>>dp(n, vector<int>(1e3, 0)) ;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < i ; j ++){
                dp[i][(a[i] + a[j]) % k] = 
                max(dp[i][(a[i] + a[j]) % k],
                    dp[j][(a[i] + a[j]) % k] + 1);
                ans = max(ans, dp[i][(a[i] + a[j]) % k]) ;
            }
        }
        return ans + 1 ;
    }
};