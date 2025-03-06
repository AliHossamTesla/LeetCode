class Solution {
    public int[] findMissingAndRepeatedValues(int[][] g) {
        int n = g.length ;
        int[] cnt = new int[n * n + 1] ;
        for(int i = 0  ;i < n ; i ++)
            for(int j = 0 ; j < n ; j ++)
                cnt[g[i][j]] ++ ;
        int a = -1, b = -1 ;
        for(int i = 1; i <= n * n ; i ++){
            if(cnt[i] == 0) b = i ;
            if(cnt[i] == 2) a = i ;
        }
        return new int[]{a, b};
    }
}