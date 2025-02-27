class Solution {
    public int lenLongestFibSubseq(int[] a) {
        int n = a.length;
        int[][] dp = new int[n][n];
        int ans = 0 ;
        Map<Integer, Integer> idx = new HashMap<>();
        for(int i = 0 ; i < n ;i ++) idx.put(a[i], i);
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < i ;j ++){
                dp[i][j] = 2 ;
                int k = idx.getOrDefault(a[i] - a[j], -1);
                if(k != -1 && dp[i][j] < dp[j][k] + 1){
                    dp[i][j] = dp[j][k] + 1 ;
                }
                if(dp[i][j] > 2) ans = Math.max(ans, dp[i][j]);
            }
        }
        return ans ;
    }
}