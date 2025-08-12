#define i64 long long
class Solution {
public:
    const i64 MOD = 1e9 + 7 ;
    int numberOfWays(int n, int x) {
        vector<vector<i64>>dp(n + 1, vector<i64>(n + 1)) ;
        dp[0][0] = 1 ;
        for(int i = 1 ; i <= n  ;i ++){
            i64 vl = pow(i, x) ;
            for(int j = 0 ; j <= n ; j ++){
                dp[i][j] = dp[i - 1][j] ;
                if(j >= vl) 
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - vl])%MOD ;
            }
        }
        return dp[n][n] ;
    }
};