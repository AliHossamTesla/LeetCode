class Solution {
public:
    int numTilings(int n) {
        long long dp[1001] = {} ;
        dp[0] = 1 ;
        for(int i = 1 ; i <= n ; i ++){
            dp[i] += dp[i - 1] ;
            if(i > 1) dp[i] += dp[i - 2] ;
            if(i > 2) dp[i] += 2*dp[i - 3] ;
            for(int j = i - 4 ; j >= 0 ; j -= 2){
                dp[i] += 2*dp[j] ;
            }
            for(int j = i - 5 ; j >= 0 ; j -= 2){
                dp[i] += 2*dp[j] ;
            }
            dp[i] %= (1000000007) ;
        }
        return dp[n];
    }
};