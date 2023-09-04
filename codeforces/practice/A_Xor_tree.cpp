#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N ; cin >> N ;
    vector<int>adj[N + 1] ;
    for(int i = 1 ; i < N ; i ++){
        int u , v ; cin >> u >> v ;
        adj[u].push_back(v) ; adj[v].push_back(u) ;
    }
    vector<int>A(N + 1,0) , B(N + 1,0) ;
    for(int i = 1 ; i <= N ; i ++)
        cin >> A[i] ;
    for(int i = 1 , j = 0 ; i <= N ; i ++)
        cin >> j , A[i] ^= j ;
    int ans = 0 ;
    function<void(int,int,int,int)> dfs = [&](int u,int parent,int cur,int prev)->void{
        if(cur != A[u]){
            ans ++ ;
            B[u] = 1 ;
            cur ^= 1 ;
        }
        for(auto son : adj[u]){
            if(son == parent) continue ;
            dfs(son,u,prev,cur) ;
        }
    };
    dfs(1,0,0,0) ;
    cout << ans << endl ;
    for(int i = 1 ; i <= N ;  i++)
        if(B[i])
            cout << i << endl ;
}
