class Solution {
    int n ;
    long[] dp;
    public long mostPoints(int[][] q) {
        n = q.length ;
        dp = new long[n];
        Arrays.fill(dp, -1);
        return calc(0, q);
    }
    private long calc(int i, int[][] q){
        if(i >= n) return 0 ;
        if(dp[i] != -1) return dp[i];
        return dp[i] = Math.max(q[i][0] + calc(i + q[i][1] + 1, q), calc(i + 1, q));
    }
}