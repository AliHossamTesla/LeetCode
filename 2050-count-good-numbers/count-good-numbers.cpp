class Solution {
public:
    const int MOD = 1e9 + 7 ;
    long long fast_pow(long long a, long long b){
        if(b == 0) return 1 ;
        return (b & 1 ? (a * fast_pow(a, b - 1)) % MOD : fast_pow((a * a) % MOD, b/2)) ;
    }
    int countGoodNumbers(long long n) {
        return (fast_pow(4, n/2) * fast_pow(5, (n + 1)/2)) % MOD ; 
    }
};