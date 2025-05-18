class Solution {
public:
    struct LCA{
        int n, LG;
        vector<vector<int>>p;
        vector<vector<array<int, 2>>>g ;
        vector<int>depth, time_in, time_out, distt, cnt;
        int time ;
        LCA(int n):n(n){
            LG = 0 ;
            while((1 << LG) <= n) LG ++ ;
            p = vector<vector<int>>(n, vector<int>(LG)) ;
            g.resize(n) ;
            depth.assign(n, 0) ;
            time_in.assign(n, 0) ;
            cnt.assign(n, 0) ;
            time_out.assign(n, 0) ; 
            time = 0 ;
        }
        void edge(int u, int v, int w){
            g[u].push_back({v, w}) ;
            g[v].push_back({u, w}) ;
        }
        void dfs(int u, int par){
            time_in[u] = ++time ;
            for(auto t : g[u]){
                int v = t[0], w = t[1] ;
                if(v == par) continue; 
                depth[v] = depth[u] + 1 ;
                cnt[v] = cnt[u] + w ;
                p[v][0] = u ;
                for(int i = 1 ; i < LG ; i ++){
                    p[v][i] = p[p[v][i - 1]][i - 1] ;
                }
                dfs(v, u) ;
            }
            time_out[u] = ++time ;
        }
        bool is_ancestor(int u, int v){
            return time_in[u] <= time_in[v] && time_out[u] >= time_out[v];
        }
        int lca(int u, int v){
            if(depth[u] < depth[v]) swap(u, v) ;
            if(is_ancestor(v, u)){
                return v;
            }
            int dif = depth[u] - depth[v] ;
            for(int i = 0 ; i < LG ; i ++){
                if(dif >> i & 1){
                    u = p[u][i] ;
                }
            }
            if(u == v) return u ;
            for(int i = LG - 1 ;i >= 0 ; i --){
                if(p[u][i] != p[v][i]){
                    u = p[u][i] ;
                    v = p[v][i] ;
                }
            }
            return p[u][0];
        }
        void build(int source = 0){
            p[source][0] = source ;
            for(int i = 1 ; i < LG ; i++){
                p[source][i] = p[p[source][i - 1]][i - 1];
            }
            dfs(source, -1) ;
        }
        int k_ancestor(int u, int k){
            if(depth[u] < k) return -1 ;
            for(int i = 0 ; i < LG ; i ++){
                if(k >> i & 1){
                    u = p[u][i] ;
                }
            }
            return u ;
        }
        int dist(int u, int v){
            return depth[u] + depth[v] - 2 * depth[lca(u, v)] ;
        }
        // LCA of u,v when tree is rooted at r
        int dynamic_lca(int r, int u, int v) {
            return ((lca(u, v) + 1) ^ (lca(u, r) + 1) ^ (lca(v, r) + 1)) - 1;
        }
        int find_place(int u, int v, int c){ // can move only c edges and want to go to v.
            int tot_dist = dist(u, v);
            if(tot_dist <= c) return v ;
            int d = dist(u, lca(u, v));
            if(d >= c){
                return k_ancestor(u, c) ;
            }else{
                return k_ancestor(v, tot_dist - c) ;
            }
        }
        int kth_node_in_path(int u, int v, int k){
            if(k == 1) return u ;
            k -- ;
            int x = lca(u, v) ;
            int l = dist(u, x) ;
            if(l >= k) return k_ancestor(u, k) ;
            else return k_ancestor(v, dist(u, v) - k) ;
        }
        bool on_path(int x, int y, int z){ // Check whether the node z is on path (x, y)
            int l = lca(x, y);
    		int l1 = lca(x, z);
    		int l2 = lca(y, z);
    
    		if (l == z || (l1 == l && l2 == z) || (l2 == l && l1 == z)) {
    			return true;
    		}
    		return false;
        }
    };
    vector<int> minimumWeight(vector<vector<int>>& e, vector<vector<int>>& q) {
        int n = e.size() + 1 ;
        LCA l(n) ;
        for(auto v : e){
            l.edge(v[0], v[1], v[2]) ;
        }
        l.build();
        vector<int>ans ;
        for(auto v : q){
            int s1 = v[0], s2 = v[1], d = v[2] ;
            int x = l.lca(s1, d) ;
            int y = l.lca(s2, d) ;
            int z = l.dynamic_lca(d, s1, s2) ;
            int cur = l.cnt[s1] + l.cnt[d] - 2*l.cnt[x];
            cur += l.cnt[s2] + l.cnt[d] - 2*l.cnt[y] ;
            int zz = l.lca(z, d) ;
            cur -= (l.cnt[d] + l.cnt[z] - 2*l.cnt[zz]) ;
            ans.push_back(cur) ;
        }
        return ans ;
    }
};