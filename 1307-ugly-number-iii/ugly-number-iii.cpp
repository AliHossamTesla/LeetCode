#define i64 long long
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        i64 v[] = {a, b, c} ;
        i64 l = n, r = n ;
        auto lcm = [&](i64 a, i64 b) ->i64 {
            return a * (b/gcd(a, b)) ;
        };
        auto num = [&](int N){
            i64 ans = 0 ;
            for(int msk = 1 ; msk < 1 << 3 ; msk ++){
                i64 l = 1 ;
                for(int i = 0 ; i < 3 ; i ++){
                    if(msk >> i & 1){
                        l = lcm(l, v[i]) ;
                    }
                }
                i64 cnt = N/l ;
                if(__builtin_popcount(msk) & 1) ans += cnt ;
                else ans -= cnt ;
            }
            return ans >= n;
        };
        while(!num(r)) r <<= 1 ;
        while(l <= r){
            int md = l + (r - l)/2 ;
            if(num(md)) r = md - 1;
            else l = md + 1 ;
        }
        return l ;
    }
};