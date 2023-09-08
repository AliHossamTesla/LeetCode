/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N , M ; cin >> N >> M ;
    vector<int>adj[N + 1] ;
    for(int i = 0 ; i < M ; i ++){
        int u , v ; cin >> u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u);
    }
    vector<int>vis(N + 1,0) ;
    function<void(int, int&, int&)> dfs = [&](int u, int& numVertics, int& numAdges)->void{
        numVertics ++ ;
        numAdges += adj[u].size() ;
        vis[u] = 1;
        for(int v: adj[u])
            if(!vis[v]) dfs(v,numVertics,numAdges) ;
    };
    bool ans = 1;
    for (int i = 1; i < N; i++)
    {
        if(!vis[i]){
            int numVertics = 0 , numAdges = 0 ;
            dfs(i,numVertics,numAdges) ;
            ans &= (numAdges == (numVertics *(numVertics - 1))) ;
        }
    }
    cout << (ans ? "YES\n" : "NO\n") ;
}