class Solution {
public:
    bool isZeroArray(vector<int>& a, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n = a.size() ;
        vector<int>b(n + 1) ;
        for(auto v : queries){
            b[v[1] + 1] -- ;
            b[v[0]] ++ ;
        }
        for(int i = 1 ; i < n ; i ++){
            b[i] += b[i - 1] ;
            if(a[i] > b[i]) return false ;
        }
        return b[0] >= a[0] ;
    }
};