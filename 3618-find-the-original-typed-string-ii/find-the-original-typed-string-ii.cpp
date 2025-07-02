class Solution {
public:
    int possibleStringCount(string s, int k) {
        // dp[i][j] number of ways to to construct a string 
        // using the first i+1 elements of freq such that 
        // the total constructed length is j
        // dp[i][j] = sum(dp[i - 1][j - k]) for 1 <= k <= a[i] 
        // dp[i - 1][j - 1] + dp[i - 1][j - 2] + ... + dp[i - 1][j - a[i]] -> 1
        // let say prf[i - 1][j] = sum(dp[i - 1][k]) for 1 <= k <= j
        // from 1 dp[i][j] = prf[i - 1][j - 1] - prf[i - 1][j - a[i] - 1] 
        const long long MOD = 1e9 + 7 ;
        vector<long long>a ;
        long long cnt = 1 ;
        for(int i = 1 ; i < s.size() ; i ++){
            if(s[i] == s[i - 1]) cnt ++ ;
            else{
                a.push_back(cnt) ;
                cnt = 1 ;
            }
        }
        a.push_back(cnt) ;
        long long ans = 1 ;
        for(long long i : a){
            ans = (ans * i) % MOD ;
        }
        if(a.size() >= k) return ans ;
        vector<long long> dp(k), f(k, 1);
        dp[0] = 1 ;
        for(int i = 0 ; i < a.size() ; i ++){
            vector<long long>ndp(k), nf(k) ;
            for(int j = 1 ; j < k ; j ++){
                ndp[j] = f[j - 1];
                if(j - a[i] - 1 >= 0) 
                    ndp[j] = (ndp[j] - f[j - a[i] - 1] + MOD)%MOD ;
            }
            nf[0] = ndp[0] ;
            for(int j = 1 ; j < k ; j ++){
                nf[j] = (nf[j - 1] + ndp[j])%MOD ;
            }
            dp = move(ndp) ;
            f = move(nf) ;
        }
        return (ans - f[k - 1] + MOD)%MOD ;
    }
};