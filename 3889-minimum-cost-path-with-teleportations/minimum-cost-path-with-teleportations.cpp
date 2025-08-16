#define i64 long long
class Solution {
public:
    const i64 inf = 1e15 ;
    int minCost(vector<vector<int>>& g, int k) {
        int n = g.size(), m = g[0].size() ;
        vector<vector<i64>>dp(n, vector<i64>(m, inf)) ;
        vector<int>vls ;
        dp[0][0] = 0 ;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                if(i) 
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + g[i][j]) ;
                if(j) 
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + g[i][j]) ;
                vls.push_back(g[i][j]) ;
            }
        }
        sort(begin(vls), end(vls)) ;
        vls.erase(unique(begin(vls), end(vls)), end(vls)) ;
        auto idx = [&](int v){
            return lower_bound(begin(vls), end(vls), v) - begin(vls) ;
        };
        for(int t = 1 ; t <= k ; t ++){
            vector<vector<i64>>ndp(n, vector<i64>(m, inf)) ;
            // build suf 
            vector<i64>best(vls.size(), inf) ;
            for(int i = 0 ; i < n ; i ++){
                for(int j = 0 ; j < m ; j ++){
                    int l = idx(g[i][j]);
                    best[l] = min(best[l], dp[i][j]) ;
                }
            }
            for(int i = best.size() - 2 ; i >= 0 ; i --){
                best[i] = min(best[i], best[i + 1]) ;
            }
            for(int i = 0 ; i < n ; i ++){
                for(int j = 0 ; j < m ; j ++){
                    ndp[i][j] = min(dp[i][j], best[idx(g[i][j])]) ;
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i) ndp[i][j] = min(ndp[i][j], ndp[i-1][j] + g[i][j]);
                    if (j) ndp[i][j] = min(ndp[i][j], ndp[i][j-1] + g[i][j]);
                }
            }
            dp = ndp ;
        }
        return dp[n - 1][m - 1] ;
    }
};