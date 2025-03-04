class Solution {
    public int countGoodStrings(int l, int r, int z, int o) {
        long[] dp = new long[r + 1];
        dp[0] = 1 ;
        for(int i = 1 ;i <= r ; i ++){
            if(i - z >= 0) dp[i] += dp[i - z];
            if(i - o >= 0) dp[i] += dp[i - o];
            dp[i] %= 1_000_000_007 ;
        }
        long ans = 0 ;
        for(int i = l ;i <= r ; i ++){
            ans = (ans + dp[i]) % 1_000_000_007;
        }
        return (int)ans ;
    }
}