/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    const int MOD = 1e9 + 7 ;
    int N , K ; cin >> N >> K ;
    vector<int>adj[N + 1] ;
    function<int(int,int)> init = [&](int n ,int k) ->int {
        if(n == 0) return 0 ;
        else if(k == 0) return 1 ;
        else if(k&1) return ((n%MOD)*(init(n,k - 1) % MOD))%MOD ;
        else return (init((n*n)%MOD,k/2))%MOD ;
    };
    int ans = init(N,K) ;
    for(int i = 0 ; i < N - 1 ; i ++){
        int u , v , selector ; 
        cin >> u >> v >> selector ;
        if(selector == 1) continue ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }
    vector<bool>vis(N + 1) ;
    function<void(int,int&)> dfs = [&](int u,int&cnt)->void {
        vis[u] = 1 ;
        cnt ++ ;
        for(auto v : adj[u]) if(!vis[v]) dfs(v,cnt) ;
    }; 
    for(int i = 1; i <= N; i++){
        if(!vis[i]){
            int cnt = 0 ;
            dfs(i,cnt) ;
            ans -= init(cnt,K) ;
            ans += MOD ;
            ans %= MOD ;
        }
    }
    cout << ans << endl ;
}
