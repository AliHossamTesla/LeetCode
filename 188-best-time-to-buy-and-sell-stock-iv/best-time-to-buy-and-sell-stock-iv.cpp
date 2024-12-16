class Solution {
public:
    int maxProfit(int k, vector<int>& a) {
        int n = a.size(), ans = 0;
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1e9))) ;
        dp[0][1][1] = -a[0] ;
        dp[0][0][0] = 0 ;
        for(int i = 1 ; i < n ; i ++){
            for(int j = 0 ; j <= min(i + 1, k) ; j ++){
                dp[i][j][0] = max(a[i] + dp[i - 1][j][1], dp[i - 1][j][0]);
                if(j) dp[i][j][1] = -a[i] + dp[i - 1][j - 1][0] ;
                dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1]) ;
                ans = max({ans, dp[i][j][1], dp[i][j][0]}) ;
            }
        }
        return ans ;
    }
};