class Solution {
public:
    vector<int> BFS_rooted(int s, vector<vector<int>> &g){
        int even = 0;
        queue<int>q ;
        q.push(s);
        vector<int>dist(g.size(), -1) ;
        dist[s] = 0 ;
        while(!q.empty()){
            int u = q.front() ; q.pop() ;
            for(int v : g[u]) if(dist[v] == -1){
                dist[v] = 1 - dist[u];
                q.push(v) ;
            }
        }
        return dist ;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
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
        vector<int>l = BFS_rooted(0, g2);
        vector<int>r = BFS_rooted(0, g1);
        int cnt = 0 ;
        for(int i = 0 ; i < m ; i ++) cnt += l[i] ;
        cnt = max(cnt, m - cnt) ;
        int ct[2] = {} ;
        for(int i = 0 ; i < n ;i ++) ct[r[i]] ++ ;
        vector<int>ans(n) ;
        for(int i = 0  ;i < n ; i ++){
            ans[i] = ct[r[i]] + cnt ;
        }
        return ans ;
    }
};