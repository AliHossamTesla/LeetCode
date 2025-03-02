class Solution {
    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int n = edges.length ;
        int[][] dist = new int[2][n] ;
        Arrays.fill(dist[0], Integer.MAX_VALUE);
        Arrays.fill(dist[1], Integer.MAX_VALUE);
        dist[0][node1] = dist[1][node2] = 0 ;
        dfs(node1, edges, dist, 0);
        dfs(node2, edges, dist, 1);
        int ans = Integer.MAX_VALUE ;
        int res = -1 ;
        for(int i = 0 ; i < n ; i ++){
            if(dist[0][i] < Integer.MAX_VALUE && dist[1][i] < Integer.MAX_VALUE &&
               Math.max(dist[0][i], dist[1][i]) < ans){
                ans = Math.max(dist[0][i], dist[1][i]);
                res = i ;
            }
        }
        return res ;
    }
    private void dfs(int u, int[] edges, int[][] dist, int st){
        int v = edges[u];
        if(v == -1) return ;
        if(dist[st][u] + 1 < dist[st][v]){
            dist[st][v] = dist[st][u] + 1;
            dfs(v, edges, dist, st);
        }
    }
}