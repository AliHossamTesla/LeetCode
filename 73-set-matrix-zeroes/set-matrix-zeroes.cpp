class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size() ;
        vector<int>clm(m), rw(n) ;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                if(mat[i][j] == 0){
                    rw[i] = clm[j] = 1 ;
                }
            }
        } 
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                if(rw[i] || clm[j]){
                    mat[i][j] = 0 ;
                }
            }
        }
    }
};