class Solution {
    public int reachableNodes(int n, int[][] edges, int[] restricted) {
        int[] vis = new int[n] ;
        for(int i : restricted) vis[i] = 2 ;
        List<Integer>[] adj = new List[n];
        for(int i = 0  ;i < n ; i ++) adj[i] = new ArrayList<>();
        for(int[] e : edges){
            adj[e[0]].add(e[1]);
            adj[e[1]].add(e[0]);
        }
        dfs(0, adj, vis);
        int ans = 0 ;
        for(int i = 0 ; i < n ; i ++) if(vis[i] == 1) ans ++ ;
        return ans ;
    }
    private void dfs(int u, List<Integer>[] adj, int[] vis){
        vis[u] = 1 ;
        for(int v : adj[u]){
            if(vis[v] == 0){
                dfs(v, adj, vis);
            }
        }
    }
}