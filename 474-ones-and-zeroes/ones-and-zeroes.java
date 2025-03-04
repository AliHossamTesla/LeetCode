class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] a = new int[strs.length][2] ;
        int i = 0;
        for(String s : strs){
            int m_ = 0;
            int n_ = 0;
            for(char c : s.toCharArray()){
                if(c == '0') m_ ++ ;
                else n_ ++ ;
            }
            a[i++] = new int[]{m_, n_};
        }
        int[][][] dp = new int[strs.length + 1][m + 1][n + 1];
        int ans = 0 ;
        for(i = 1; i <= strs.length ; i ++){
            for(int m_ = 0 ; m_ <= m ; m_ ++){
                for(int n_ = 0 ; n_ <= n ; n_ ++){
                    dp[i][m_][n_] = dp[i - 1][m_][n_];
                    if(m_ - a[i - 1][0] >= 0 && n_ - a[i - 1][1] >= 0){
                        dp[i][m_][n_] = Math.max(dp[i][m_][n_], 1 + dp[i - 1][m_ - a[i - 1][0]][n_ - a[i - 1][1]]);
                    }
                    ans = Math.max(ans, dp[i][m_][n_]);
                }
            }
        }
        return ans ;
    }
}