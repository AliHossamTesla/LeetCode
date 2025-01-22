import java.util.Queue;
class Pair{
    int x ;
    int y ;
    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
class Solution {
    public int[][] highestPeak(int[][] a) {
        int n = a.length;
        int m = a[0].length;
        Queue<Pair> q = new LinkedList<>();
        int[][] vis = new int[n][m];
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                if(a[i][j] == 1){
                    a[i][j] = 1 ;
                    q.offer(new Pair(i, j));
                    vis[i][j] = 1;
                    a[i][j] = 0;
                }
            }
        }
        int[][] dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.isEmpty()){
            Pair current = q.poll(); 
            int x = current.x;
            int y = current.y;

            for (int[] d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] == 0) {
                    a[nx][ny] = a[x][y] + 1;
                    vis[nx][ny] = 1;
                    q.offer(new Pair(nx, ny));
                }
            }
        }
        return a ;
    }
}