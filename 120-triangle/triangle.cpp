class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n = t.size();
        vector<int>dp(1) ;
        dp[0] = t[0][0] ;
        for(int i = 1 ; i < n ; i ++){
            int m = t[i].size() ;
            vector<int>ndp(m, 1E9) ;
            for(int j = 0 ; j < m ; j ++){
                if(j < m - 1){
                    ndp[j] = t[i][j] + dp[j] ;
                }
                if(j) ndp[j] = min(ndp[j], t[i][j] + dp[j - 1]) ;
            }
            dp = vector<int>(m) ;
            dp = ndp ;
        }
        return *min_element(begin(dp), end(dp)) ;
    }
};