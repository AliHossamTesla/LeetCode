class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1] ;
        Arrays.fill(dp, 1_000_000_000);
        dp[0] = 0 ;
        for(int i = 1 ; i <= amount ; i ++){
            for(int c : coins) if(i - c >= 0 && dp[i - c] != 1_000_000_000){
                dp[i] = Math.min(dp[i], 1 + dp[i - c]);
            }
        }
        return dp[amount] == 1_000_000_000 ? -1 : dp[amount];
    }
}