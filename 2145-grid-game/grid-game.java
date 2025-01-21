class Solution {
    public long gridGame(int[][] g) {
        int n = g[0].length;
        if(n == 1) return 0 ;
        long[] pref = new long[n];
        long[] suf = new long[n] ;
        pref[0] = g[1][0] ;
        suf[n - 1] = g[0][n - 1] ;
        for(int i = 1 ; i < n ; i ++){
            pref[i] += pref[i - 1] + g[1][i];
            suf[n - i - 1] += suf[n - i] + g[0][n - i - 1];
        }
        long ans = suf[1] ;
        for(int i = 1 ; i < n - 1 ; i ++){
            ans = Math.min(ans, Math.max(suf[i + 1], pref[i - 1])) ;
        }
        ans = Math.min(ans, pref[n - 2]) ;
        return ans ;
    }
}