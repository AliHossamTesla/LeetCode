class Solution {
public:
    long long minSum(vector<int>& a, vector<int>& b) {
        long long x = -1, y = -1, l = 0, r = 0 ;
        for(int i = 0 ; i < a.size() ; i ++){
            if(a[i] == 0 && x == -1){
                x = i ;
            }
            if(a[i] == 0) a[i] = 1;
            l += a[i] ;
        }
        for(int i = 0 ; i < b.size() ; i ++){
            if(b[i] == 0 && y == -1){
                y = i ;
            }
            if(b[i] == 0) b[i] = 1;
            r += b[i] ;
        }
        if(l == r){
            return l ;
        }
        if((l > r && y != -1) || (r > l && x != -1)){
            return max(l, r) ;
        }else return -1 ;
    }
};