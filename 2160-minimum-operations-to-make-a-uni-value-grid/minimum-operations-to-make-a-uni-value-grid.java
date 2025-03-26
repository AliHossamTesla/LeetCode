class Solution {
    public int minOperations(int[][] g, int x) {
        int n = g.length;
        int m = g[0].length;
        int[] a = new int[n * m] ;
        for(int i = 0 , k = 0; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                a[k ++] = g[i][j];
                g[i][j] %= x ;
                if(g[i][j] != g[0][0]){
                    return -1 ;
                }
            }
        }
        Arrays.sort(a);
        int l = 0, r = 0 ;
        int ans = Integer.MAX_VALUE ;
        for(int i = 0 ; i < n * m ; i ++) r += a[i];
        for(int i = 0  ;i < n * m ; i ++){
            if(i > 0) l += a[i - 1];
            r -= a[i] ;
            int cr = (r - (n * m - i - 1)*a[i])/x + (i*a[i] - l)/x ;
            ans = Math.min(ans, cr);
        }
        return ans ;
    }
}