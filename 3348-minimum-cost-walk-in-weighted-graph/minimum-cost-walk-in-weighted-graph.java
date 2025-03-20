class Solution {
    int identifer = 0 ;
    List<int[]>[] adj ;
    boolean[] vis ;
    int[] idx ;
    List<Integer> vl = new ArrayList<>();
    private int dfs(int u){
        idx[u] = identifer;
        vis[u] = true ;
        int vl = ((1 << 30) - 1);
        for(int[] v : adj[u]){
            vl &= v[1] ;
            if(!vis[v[0]]) vl &= dfs(v[0]);
        }
        return vl ;
    }
    public int[] minimumCost(int n, int[][] edges, int[][] query) {
        adj = new List[n];
        vis = new boolean[n];
        idx = new int[n];
        for(int i = 0 ; i < n ; i ++) adj[i] = new ArrayList<>();
        for(int[] e : edges){
            adj[e[0]].add(new int[]{e[1], e[2]});
            adj[e[1]].add(new int[]{e[0], e[2]});
        }
        for(int i = 0; i < n ; i ++)if(!vis[i]){
            vl.add(dfs(i));
            identifer ++ ;
        }
        // System.out.println(vl);
        int[] ans = new int[query.length];
        for(int i = 0 ; i < query.length ; i ++){
            if(idx[query[i][0]] == idx[query[i][1]]){
                ans[i] = vl.get(idx[query[i][0]]);
            }else ans[i] = -1 ;
        }
        return ans ;
    }
}