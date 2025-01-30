class Solution {
    public int magnificentSets(int n, int[][] e) {
        ArrayList<Integer>[] adj = (ArrayList<Integer>[]) new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        for(int[] a : e){
            adj[a[0] - 1].add(a[1] - 1) ;
            adj[a[1] - 1].add(a[0] - 1) ;
        }
        boolean[] vis = new boolean[n];
        int ans = 0 ;
        for(int i = 0 ; i < n ; i ++)if(!vis[i]){
            ArrayList<Integer>nodes = new ArrayList<>();
            dfs(i, vis, adj, nodes);
            int cr = 0 ;
            for(int u : nodes){
                cr = Math.max(cr, tryBFS(u, adj));
            }
            if(cr == 0) return -1;
            ans += cr ;
        }
        return ans ;
    }
    private int tryBFS(int s, ArrayList<Integer>[] adj){
        int n = adj.length;
        int[] dist = new int[n];
        Arrays.fill(dist, -1);
        dist[s] = 1;
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(s);
        int ans = 1 ;
        while(!q.isEmpty()){
            int u = q.poll();
            for(int v : adj[u]){
                if(dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    ans = Math.max(ans, dist[v]);
                    q.add(v);
                }else{
                    if(dist[v] != dist[u] + 1 && dist[v] != dist[u] - 1){
                        return 0 ;
                    }
                }
            }
        }
        return ans;
    }
    private void dfs(int u, boolean[] vis, ArrayList<Integer>[] adj, ArrayList<Integer> nodes){
        vis[u] = true ;
        nodes.add(u);
        for(int v : adj[u]){
            if(!vis[v]){
                dfs(v, vis, adj, nodes);
            }
        }
    }
}