/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    const int MOD = 1e9 + 7 ;
    int N , M ; cin >> N >> M ;
    vector<int>A(N) ;
    for(int i = 0 ; i < N ; i ++)
        cin >> A[i];
    vector<vector<int>>dp(N,vector<int>(M + 1,-1)) ;
    function<int(int, int)> solve = [&](int idx, int prev) -> int{
        if(idx < 0)
            return 1;
        if (~dp[idx][prev]) return dp[idx][prev];
        if (A[idx] == 0){
            dp[idx][prev] = solve(idx - 1, prev);
            if (prev + 1 <= M)
                dp[idx][prev] = (dp[idx][prev] + solve(idx - 1, prev + 1)) % MOD;
            if (prev - 1 > 0)
                dp[idx][prev] = (dp[idx][prev] + solve(idx - 1, prev - 1)) % MOD;
            return dp[idx][prev];
        }else{
            if (A[idx] > M or A[idx] <= 0 or abs(A[idx] - prev) > 1)
                return 0;
            return dp[idx][prev] = solve(idx - 1, A[idx]) % MOD;
        }
    };
    if(A[N - 1] == 0){
        int ans = 0 ;
        for(int i = 1 ; i <= M ; i ++)
            ans = (ans + solve(N - 2,i))%MOD ;
        cout << ans << endl ;
    }else cout << solve(N - 2,A[N - 1]) ;
}
