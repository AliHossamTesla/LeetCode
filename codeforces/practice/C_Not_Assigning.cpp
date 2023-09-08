#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T ; cin >> T ;
    while(T--){
        int N ; cin >> N ;
        vector<int>adj[N + 1],deg(N + 1,0);
        vector<pair<int,int>>A ;
        bool bad = 0 ;
        for(int i = 0 ; i < N - 1; i ++){
            int u , v ; cin >> u >> v ;
            if(u > v) swap(u,v) ;
            A.push_back({u,v}) ;
            adj[u].push_back(v) ; adj[v].push_back(u) ;
            deg[u] ++ ; deg[v] ++ ;
            if(deg[u] > 2 or deg[v] > 2)
                bad = 1 ;
        }
        if(bad){
            cout << -1 << endl ;
            continue ;
        }
        map<pair<int,int>,int>mp ;
        function<void(int, int, int, int)> dfs = [&](int u, int parent, int cur, int prev) -> void
        {
            for (auto son : adj[u])
            {
                if (son == parent)
                    continue;
                int x = u , y = son ;
                if(x > y) swap(x,y) ;
                mp[{x,y}] = cur ;
                dfs(son, u, prev, cur);
            }
        };
        int node = -1 ;
        for(int i = 1 ; i <= N ; i ++) if(deg[i] == 1) node = i ;
        dfs(node,0, 2, 3);
        for(int i = 0 ; i < N - 1 ; i ++)
            cout << mp[A[i]] << " \n"[i + 2 == N] ; 
    }
}
