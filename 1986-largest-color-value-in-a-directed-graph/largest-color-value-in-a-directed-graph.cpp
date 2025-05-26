class Solution {
public:
    int largestPathValue(string col, vector<vector<int>>& edges) {
        // dp[u][i] number of accurance of color i until node u.
        // ans = max(dp[u]), 1 <= u <= n 
        // check for cycles first then will be start node if not.
        int n = col.size(); 
        vector<vector<int>>g(n) ;
        vector<int> color(n, 0), parent(n, -1), deg(n, 0);
        for(auto t : edges){
            int u = t[0], v = t[1] ;
            g[u].push_back(v) ;
            deg[v] ++ ;
        }
        function<bool(int v)> dfs = [&](int v){
            color[v] = 1;
            for (int u : g[v]) {
                if (color[u] == 0) {
                    parent[u] = v;
                    if (dfs(u))
                        return true;
                } else if (color[u] == 1) {
                    return true;
                }
            }
            color[v] = 2;
            return false;
        };
        for (int v = 0; v < n; v++) {
            if (color[v] == 0 && dfs(v))
                return -1 ;
        }
        vector<vector<int>>dp(n, vector<int>(26, 0)) ;
        queue<int>q ;
        for(int i = 0 ; i < n ; i ++)
            if(deg[i] == 0){
                q.push(i) ;
                dp[i][col[i] - 'a'] = 1 ;
            }
        while(!q.empty()){
            int u = q.front() ; q.pop() ;
            for(int v : g[u]){
                for(int i = 0 ; i < 26 ; i ++){
                    dp[v][i] = max(dp[v][i], dp[u][i] + (col[v] - 'a' == i)) ;
                }
                if(--deg[v] == 0){
                    q.push(v) ;
                }
            } 
        }
        int ans = 0 ;
        for(int i = 0 ; i < n ; i ++){
            ans = max(ans, *max_element(begin(dp[i]), end(dp[i]))) ;
        }
        return ans ;
    }
};