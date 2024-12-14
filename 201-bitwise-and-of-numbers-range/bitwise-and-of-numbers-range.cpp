class Solution {
public:
    int msbPosition(int n) {
        return (n > 0) ? 31 - __builtin_clz(n) : -1; // For 32-bit integers
    }

    int rangeBitwiseAnd(int l, int r) {
        int ans = 0 ;
        while(l && r){
            int x = msbPosition(l), y = msbPosition(r) ;
            if(x != y){
                break ;
            }
            ans += (1 << x) ;
            
            l -= (1 << x) ;
            r -= (1 << y) ;
        }
        return ans ;
    }
};