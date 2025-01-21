class Solution {
    public long gridGame(int[][] g) {
        long ans = Long.MAX_VALUE ;
        long pref = 0 ;
        long suf = 0 ;
        for(int i : g[0])
            suf += i ;
        for(int i = 0 ; i < g[0].length ; i ++){
            suf -= g[0][i];
            ans = Math.min(ans, Math.max(suf, pref)) ;
            pref += g[1][i] ;
        }
        return ans ;
    }
}