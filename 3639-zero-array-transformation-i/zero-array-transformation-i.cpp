class Solution {
public:
    bool isZeroArray(vector<int>& a, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        vector<int>b(a.size() + 1) ;
        for(auto v : queries){
            b[v[1] + 1] -- ;
            b[v[0]] ++ ;
        }
        for(int i = 0 ; i < a.size() ; i ++){
            if(i) b[i] += b[i - 1] ;
            if(a[i] > b[i]) return false ;
        }
        return true ;
    }
};