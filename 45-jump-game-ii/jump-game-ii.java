class Solution {
    public int jump(int[] a) {
        int n = a.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 1_000_000_000);
        dp[0] = 0 ;
        for(int i = 0 ; i < n - 1; i ++){
            for(int j = i ; j <= i + a[i] && j < n ; j ++){
                dp[j] = Math.min(dp[j], dp[i] + 1);
            }
        }
        return dp[n - 1];
    }
}