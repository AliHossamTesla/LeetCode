class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size(), m = mat[0].size() ;
        vector<vector<int>>pref(n + 1, vector<int>(m + 1, 0)) ;
        for(int i = 1 ; i <= n ; i ++)
            for(int j = 1 ; j <= m ; j ++)
                pref[i][j] = pref[i][j - 1] + (mat[i - 1][j - 1] == '1') ;
        
        for(int i = 1 ;i <= n ; i ++)
            for(int j = 1 ; j <= m; j ++)
                pref[i][j] += pref[i - 1][j] ;
        
        auto calc = [&](int i, int j, int k){
            return pref[i + k + 1][j + k + 1] - 
                   pref[i + k + 1][j] - pref[i][j + k + 1] + 
                   pref[i][j] ;
        };
        int ans = 0 ;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                for(int k = 0 ; k + i < n && k + j < m ; k ++){
                    int cr = calc(i, j, k) ;
                    // cout << i << " " << j << " " << k << " : " << cr << '\n' ;
                    if(cr == (k + 1) * (k + 1)){
                        ans = max(ans, (k + 1) * (k + 1)) ;
                    }else break ;
                }
            }
        }
        return ans ;
    }
};