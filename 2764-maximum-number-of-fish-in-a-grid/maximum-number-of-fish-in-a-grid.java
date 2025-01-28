class Solution {
    int[] dx = {-1, 1, 0, 0};
    int[] dy = {0, 0, 1, -1};
    public int findMaxFish(int[][] g) {
        int n = g.length;
        int m = g[0].length;
        boolean[][] vis = new boolean[n][m] ;
        int ans = 0;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++) if(g[i][j] > 0){
                ans = Math.max(ans, floodfill(i, j, g, vis)) ;
            }
        }
        return ans ;
    }
    private int floodfill(int x, int y, int[][] a, boolean[][] vis){
        if(x < 0 || x >= a.length || y < 0 || y >= a[0].length || a[x][y] == 0 || vis[x][y])
            return 0 ;
        int ans = a[x][y] ;
        vis[x][y] = true ;
        for(int i = 0 ; i < 4 ; i ++){
            ans += floodfill(x + dx[i], y + dy[i], a, vis);
        }
        return ans ;
    }
}