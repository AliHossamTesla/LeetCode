class Solution {
public:
    int idx(int i, int j, int n, int m){
        return i * m + j ;
    }
    pair<int,int> rev_idx(int i, int n, int m){
        return {i/m, i%m} ;
    }
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n = mat.size(), m = mat[0].size() ;
        int l = 0, r = idx(n - 1, m - 1, n, m) ;
        while(l <= r){
            int md = l + (r - l)/2 ;
            auto i = rev_idx(md, n, m) ;
            if(mat[i.first][i.second] == t) return true ;
            if(mat[i.first][i.second] > t) r = md - 1 ;
            else l = md + 1 ;
        }
        return false ;
    }
};