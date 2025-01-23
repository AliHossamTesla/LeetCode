class Solution {
    public int countServers(int[][] g) {
        int n = g.length;
        int m = g[0].length;
        int[] clm = new int[m];
        int[] rw = new int[n] ;
        for(int i = 0 ; i < n ; i ++)
            for(int j = 0 ; j < m ; j ++)
                if(g[i][j] == 1){
                    clm[j] ++ ;
                    rw[i] ++  ;
                }
        
        int ans = 0 ;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                if(g[i][j] == 1 && (clm[j] > 1 || rw[i] > 1)){
                    ans ++ ;
                    // System.out.println(i + " " + j);
                }
            }
        }
        return ans ;
    }
}