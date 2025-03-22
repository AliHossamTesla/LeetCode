class Solution {
    int[] deg ;
    int n ;
    List<Integer>[] adj ;
    int[] vis;
    public int countCompleteComponents(int n, int[][] edges) {
        this.n = n ;
        adj = new List[n];
        deg = new int[n];
        vis = new int[n];
        for(int i = 0 ; i < n ; i ++) adj[i] = new ArrayList<>();
        for(int[] e : edges){
            adj[e[0]].add(e[1]);
            adj[e[1]].add(e[0]);
            deg[e[0]] ++ ;
            deg[e[1]] ++ ;
        }
        int ans = 0 ;
        for(int i = 0 ; i < n ; i ++)if(vis[i] == 0){
            int cnt = dfs1(i);
            // for(int v = 0 ; v < n ; v ++) if(vis[v] == 1) vis[v] = 0 ;
            // System.out.println(cnt);
            if(dfs2(i, cnt - 1)){
                ans ++ ;
            }
        }  
        return ans ;
    }
    private int dfs1(int u){
        int cr = 1 ;
        vis[u] = 1 ;
        for(int v : adj[u]) if(vis[v] == 0){
            cr += dfs1(v) ;
        }
        return cr ;
    }
    private boolean dfs2(int u, int cnt){
        if(deg[u] != cnt) return false ;
        vis[u] = 2 ;
        for(int v : adj[u]) if(vis[v] == 1){
            if(!dfs2(v, cnt)) return false ;
        }
        return true ;
    }
}