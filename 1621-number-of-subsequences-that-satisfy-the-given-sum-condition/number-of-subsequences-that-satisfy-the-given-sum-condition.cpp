class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long ftpow(int b){
        long long ans = 1, base = 2;
        while(b){
            if(b & 1)
                ans = (ans * base) % MOD;
            base = (base * base) % MOD;
            b >>= 1;
        }
        return ans;
    }

    int numSubseq(vector<int>& a, int t) {
        sort(begin(a), end(a)) ;
        long long l = 0, r = a.size() - 1, ans = 0;
        while(l <= r){
            if(a[l] + a[r] > t) r -- ;
            else{
                ans += ftpow(r - l) ;
                l ++;
                ans %= MOD ;
            }
        }
        return ans;
    }
};