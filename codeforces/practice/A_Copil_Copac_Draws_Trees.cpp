/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N ; cin >> N ;
        vector<vector<pair<int,int>>>adj(N) ;
        for(int i = 0 ; i < N - 1 ; i ++){
            int u , v ; cin >> u >> v ;u -- ; v -- ;
            adj[u].push_back({v,i}) ;
            adj[v].push_back({u, i});
        }
        int ans = 0 ;
        function<void(int,int,int,int)> dfs = [&](int u,int prev,int cr_reding,int id)->void{
            ans = max(ans,cr_reding + 1) ;
            for(auto U : adj[u]){
                if(U.first == prev) continue ;
                if(U.second > id) dfs(U.first,u,cr_reding,U.second) ;
                else dfs(U.first, u, cr_reding + 1, U.second);
            }
        };
        dfs(0,-1,0,-1) ;
        cout << ans << endl ;
    }
}
