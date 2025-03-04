class Solution {
    int[] dp ;
    public int numDecodings(String s) {
        dp = new int[s.length()] ;
        Arrays.fill(dp, -1);
        return calc(0, s.length(), s.toCharArray());
    }
    private int calc(int i, int n, char[] s){
        if(i == n) return 1 ;
        if(dp[i] != -1) return dp[i];
        if(s[i] == '0') return dp[i] = 0 ;
        dp[i] = calc(i + 1, n, s);
        if(i < n - 1 && Integer.parseInt("" + s[i] + s[i + 1]) <= 26){
            dp[i] += calc(i + 2, n, s);
        }
        return dp[i];
    }
}