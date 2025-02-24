class Solution {
    int ans;

    public int mostProfitablePath(int[][] edges, int bob, int[] amount) {
        int n = edges.length + 1;
        int[] dist = new int[n];
        Arrays.fill(dist, -1);
        List<Integer>[] adj = new List[n];
        for (int i = 0; i < n; i++)
            adj[i] = new ArrayList<>();
        for (int[] e : edges) {
            adj[e[0]].add(e[1]);
            adj[e[1]].add(e[0]);
        }
        dist[0] = 0;
        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.add(0);
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : adj[u])
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.add(v);
                }
        }
        amount[bob] = 0;
        dfs(bob, -1, dist, amount, adj, 1);
        ans = Integer.MIN_VALUE;
        prefDfs(0, -1, amount, adj, 0);
        return ans;
    }

    private boolean dfs(int u, int p, int[] dist, int[] amount, List<Integer>[] adj, int cnt) {
        if (u == 0) {
            return true;
        }
        if (p != -1 && adj[u].size() == 1) {
            return false;
        }
        for (int v : adj[u])
            if (v != p) {
                if (dfs(v, u, dist, amount, adj, cnt + 1)) {
                    if (cnt == dist[v]) {
                        amount[v] /= 2;
                    } else if (cnt < dist[v]) {
                        amount[v] = 0;
                    }
                    return true;
                }
            }
        return false;
    }

    private void prefDfs(int u, int p, int[] amount, List<Integer>[] adj, int pref) {
        pref += amount[u];
        if (u != 0 && adj[u].size() == 1) {
            ans = Math.max(ans, pref);
            return;
        }
        for (int v : adj[u])
            if (v != p) {
                prefDfs(v, u, amount, adj, pref);
            }
    }
}