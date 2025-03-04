class Solution {
    int[] dp ;
    public int numDecodings(String s) {
        char[] a = s.toCharArray();
        int n = s.length() ;
        dp = new int[n + 1] ;
        dp[0] = 1 ;
        for(int i = 1 ; i <= n ; i ++){
            if(a[i - 1] != '0') dp[i] += dp[i - 1];
            if(i > 1 && (a[i - 2] == '1' || (a[i - 2] == '2' && a[i - 1] <= '6')))
                 dp[i] += dp[i - 2];
        }
        return dp[n];
    }
}