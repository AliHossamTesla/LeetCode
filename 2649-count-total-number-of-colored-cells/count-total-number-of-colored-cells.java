class Solution {
    public long coloredCells(int n) {
        long[] dp = new long[n + 1] ;
        dp[1] = 1 ;
        for(int i = 2, j = 4; i <= n ; i ++, j += 4){
            dp[i] = dp[i - 1] + j ;
        }
        return dp[n];
    }
}