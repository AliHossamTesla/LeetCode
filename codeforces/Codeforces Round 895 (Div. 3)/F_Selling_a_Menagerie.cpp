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
        vector<int>to(N + 1),C(N + 1),in(N + 1);
        for(int i = 1; i <= N; i++)
            cin >> to[i] ,in[i] ++ ;
        for(int i = 1 ; i <= N; i++)
            cin >> C[i] ;
        vector<int>ans ;
        vector<bool>inStack(N + 1),vis(N + 1,0);
        vector<int>tmp ;
        function<void(int, int)> dfs2 = [&](int u, int v) -> void{
            tmp.push_back(u);
            if (to[u] == v)
                return;
            dfs2(to[u], v);
        };
        function<void(int)> dfs1 = [&](int u) -> void{
            if(inStack[u]){
                tmp.clear() ;
                int cr = u , st = u;
                do{
                    vis[cr] = 1 ;
                    st = (C[cr] < C[st] ? cr : st);
                    cr = to[cr] ;
                }while (cr != u);
                dfs2(to[st],to[st]) ;
                reverse(tmp.begin(),tmp.end()) ;
                for(int i : tmp)
                    ans.push_back(i) ;
                return ;
            }
            inStack[u] = 1 ;
            if(to[u] and !vis[to[u]]){
                dfs1(to[u]) ;
                if(vis[u]){
                    inStack[u] = 0 ;
                    return ;
                }
            }
            ans.push_back(u);
            inStack[u] = 0 ;
            vis[u] = 1 ;

        };
        for (int i = 1; i <= N; i++) if(in[i] == 0) dfs1(i);
        for(int i = 1 ; i <= N; i++) if(!vis[i]) dfs1(i) ;
        reverse(ans.begin(), ans.end());
        for(int i = 0 ; i < ans.size() ; i++)
            cout << ans[i] << " \n"[i + 1 == ans.size()] ;
    }
}
