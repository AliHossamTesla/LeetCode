class Solution {
    public int trapRainWater(int[][] h) {
        int n = h.length;
        int m = h[0].length;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> h[a[0]][a[1]] - h[b[0]][b[1]]);
        boolean[][] vis = new boolean[n][m];

        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                if(i == 0 || j == 0 || i == n - 1 || j == m - 1){
                    pq.offer(new int[]{i, j});
                }
            }
        }
        int ans = 0 ;

        int[][] di = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!pq.isEmpty()){
            int[] cr = pq.poll() ;
            int x = cr[0] ;
            int y = cr[1] ;
            if(vis[x][y]) continue;
            vis[x][y] = true ;

            for(int i = 0 ; i < 4 ; i ++){
                int nx = x + di[i][0] ;
                int ny = y + di[i][1] ;
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]){
                    int cur = Math.max(h[x][y] - h[nx][ny], 0) ;
                    h[nx][ny] += cur ;
                    ans += cur ;
                    pq.offer(new int[]{nx, ny}) ;
                }
                
            }
        }
        return ans ;
    }
}