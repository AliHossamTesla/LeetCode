class Solution {
public:
    long long minSum(vector<int>& a, vector<int>& b) {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        long long l = 0, r = 0 ;
        bool x = 0, y = 0 ;
        for(int i = 0 ; i < a.size() ; i ++){
            if(a[i] == 0){
                l ++ ;
                x = 1 ;
            }else l += a[i] ;
        }
        for(int i = 0 ; i < b.size() ; i ++){
            if(b[i] == 0){
                r ++ ;
                y = 1;
            }else r += b[i] ;
        }
        if(l == r){
            return l ;
        }else if((l > r && y) || (r > l && x)){
            return max(l, r) ;
        }else return -1 ;
    }
};