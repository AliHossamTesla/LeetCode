/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N ,root; cin >> N ;
    vector<int>adj[N + 1],A(N + 1);
    for(int i = 1 ; i <= N ; i ++){
        int u , v ; cin >> u >> v ;
        if(u == -1){A[i] = v , root = i ; continue;}
        adj[u].push_back(i);
        adj[i].push_back(u);
        A[i] = v ;
    }
    vector<int>ans ;
    function<void(int, int)> dfs = [&](int u, int v) -> void{
        int cnt = 0 ;
        for(auto son : adj[u]){
            if(son == v)
                continue;
            cnt += A[son] ;
            dfs(son,u) ;
        }
        if(A[u] and cnt == adj[u].size() - 1)
            ans.push_back(u);
    };
    dfs(root,-1) ;
    if(ans.size() == 0) {cout << -1 << endl ; return 0 ;}
    sort(ans.begin(),ans.end()) ;
    for(int &i : ans)
        cout << i << " " ;
    cout << endl; 
}
