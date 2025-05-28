class Solution {
public:
    int BFS(int s, vector<vector<int>> &g, int k){
        int ans = 0;
        queue<int>q ;
        q.push(s);
        vector<int>dist(g.size(), -1) ;
        dist[s] = 0 ;
        while(!q.empty()){
            int u = q.front() ; q.pop() ;
            if(dist[u] > k) break ;
            ans ++ ;
            for(int v : g[u]) if(dist[v] == -1){
                dist[v] = dist[u] + 1 ;
                q.push(v) ;
            }
        }
        return ans ;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1 ;
        vector<vector<int>>g1(n), g2(m) ;
        for(auto v : edges1){
            g1[v[0]].push_back(v[1]) ;
            g1[v[1]].push_back(v[0]) ;
        }
        for(auto v : edges2){
            g2[v[0]].push_back(v[1]) ;
            g2[v[1]].push_back(v[0]) ;
        }
        int pre = 0 ;
        for(int i = 0 ; i < m ; i ++) pre = max(pre, BFS(i, g2, k - 1)) ;
        vector<int>ans;
        for(int i = 0 ; i < n ; i ++){
            ans.push_back(BFS(i, g1, k) + pre) ;
        }
        return ans ;
    }
};