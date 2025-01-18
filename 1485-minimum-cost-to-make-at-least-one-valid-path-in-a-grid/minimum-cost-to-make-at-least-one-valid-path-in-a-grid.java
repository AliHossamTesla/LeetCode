class Solution {
    public int minCost(int[][] g) {
        int n = g.length ;
        int m = g[0].length ;

        int[][] di = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int dist[][] = new int[n][m] ;
        for(int[] row : dist){
            Arrays.fill(row, Integer.MAX_VALUE) ;
        }
        dist[0][0] = 0 ;

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{0, 0, 0});

        while(!pq.isEmpty()){
            int[] cr = pq.poll() ;
            int cost = cr[0];
            int x = cr[1] ;
            int y = cr[2] ;

            if(x == n - 1 && y == m - 1){
                return cost ;
            }

            for(int i = 0 ; i < 4 ; i ++){
                int nx = x + di[i][0] ;
                int ny = y + di[i][1] ;
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){

                    int nwCost = cost + (i + 1 == g[x][y] ? 0 : 1);
                    if(nwCost < dist[nx][ny]){
                        dist[nx][ny] = nwCost ;
                        pq.offer(new int[]{nwCost, nx, ny}) ;
                    }
                }
            }
        }

        return -1 ;
    }
}