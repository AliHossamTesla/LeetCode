/*The blessings of God to the Prophet Muhammad*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
struct graph{
    int N , M ;
    vector<vector<int>> adj;
    vector<bool> vis;
    vector<int>dis;
    graph(int N, int M) : N(N), M(M){
        adj = vector < vector<int> >(N + 1) ;
        vis = vector< bool > (N + 1) ;
        dis = vector<int>(N + 1,-1);
    }
    void readUnDirected()
    {
        for (int i = 0; i < M; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    void dfs(int u){
        vis[u] = 1;
        for (auto v : adj[u])
            if (!vis[v])
                dfs(v);
    }
    void dfs2(int u,int& nodes,int& edges){
        vis[u] = 1 ;
        nodes ++ ;
        for (auto v : adj[u])
            if (!vis[v])
                edges ++ , dfs2(v, nodes,edges);
    }
    int numberOfUnvisited(){return count(vis.begin() + 1,vis.end(),0);}
    void bfs(int u){
        queue<int>Q; 
        Q.push(u) ;
        dis[u] = 0 ;
        while(!Q.empty()){
            int st = Q.front() ; Q.pop() ;
            for(auto v : adj[st]){
                if(dis[v] != -1) continue ;
                dis[v] = dis[st] + 1 ;
                Q.push(v) ;
            }
        }
    }
};
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N , M , K ; cin >> N >> M >> K ;
    graph g(N,M) ;
    vector<int>Gov(K) ;
    for(int i = 0 ; i < K ; i ++)
        cin >> Gov[i] ;
    g.readUnDirected();
    vector<int>node ;
    for (int i = 0; i < K; i++)
    {
        int nodes = 0 ,edges = 0;
        g.dfs2(Gov[i],nodes,edges);
        node.push_back(nodes) ;
    }
    int res = 0 ;
    for(int i = 1;i <= N ; i ++){
        if(g.vis[i]) continue;
        int nodes = 0 , edges = 0 ;
        g.dfs2(i,nodes,edges) ;
        res += nodes ;
    }
    sort(node.rbegin(),node.rend()) ;
    node[0] += res ;
    int ans = node[0] *(node[0] - 1)/2 ;
    for(int i = 1 ; i < node.size() ; i++)
        ans += node[i] * (node[i] - 1) / 2;
    cout << ans - M << endl;
}
