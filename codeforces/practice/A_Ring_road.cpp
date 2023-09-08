/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N ; cin >> N ;
    vector<pair<int,int>>adj[N + 1];
    vector<int>out(N + 1,0) ;
    for (int i = 0; i < N; i++){
        int u , v , c ; cin >> u >> v >> c ;
        out[u] ++ ;
        adj[u].push_back({v,0});
        adj[v].push_back({u, c});
    }
    int targ = -1 ;
    for(int i = 1 ; i <= N ; i ++) if(out[i] == 2) {targ = i ; break;}
    if(targ == -1) {cout << 0 << endl ; return 0 ;}
    function<int(int,int,int)> dfs = [&](int u,int prev ,int st) ->int{
        if(u == st) return 0 ;
        if (adj[u][0].first == prev) return adj[u][1].second + dfs(adj[u][1].first,u, st);
        else return adj[u][0].second + dfs(adj[u][0].first,u, st);
    };
    cout << min(dfs(adj[targ][0].first, targ, targ), dfs(adj[targ][1].first, targ, targ)) << endl;
}
