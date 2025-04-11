class Solution {
public:
    struct kuhn{
        vector<vector<int>>g ;
        vector<int>mt, used1, used ;
        int n, m ;
        kuhn(int n_, int m_){
            n = n_, m = m_ ;
            mt.assign(m, -1) ;
            used1.assign(n, 0);
            used.assign(n, 0);
            g.resize(n) ;
        }
        
        void edge(int u, int v, int rev){ // 0-indexed, u belong to n, v belong to m
            if(!rev) swap(u, v) ;
            g[u].push_back(v) ;
        }

        bool try_kuhn(int u){
            if(used[u]) return false ;
            used[u] = 1 ;
            for(int v : g[u]){
                if(mt[v] == -1 || try_kuhn(mt[v])){
                    mt[v] = u ;
                    return true ;
                }
            }
            return false ;
        }

        int max_matching(){
            for(int i = 0 ; i < n ;  i++){
                for(int v : g[i]){
                    if(mt[v] == -1){
                        mt[v] = i ;
                        used1[i] = 1 ;
                        break ;
                    }
                }
            }
            for(int i = 0 ; i < n ; i ++)if(!used1[i]){
                used.assign(n, 0) ;
                try_kuhn(i) ;
            }
            int ans = 0 ;
            for(int i = 0 ; i < m ; i ++){
                ans += mt[i] != -1 ;
            }
            return ans ;
        }
    };
    int maxStudents(vector<vector<char>>& b) {
        int n = b.size(), m = b[0].size() ;
        vector<vector<int>>a(n, vector<int>(m)) ;
        int cnt = 0 ;
        for(int j = 1 ; j < m ; j += 2){
            for(int i = 0; i < n ; i ++){
                a[i][j] = cnt ++ ;
            }
        }
        int n_ = cnt ;
        cnt = 0 ;
        for(int j = 0 ; j < m ; j += 2){
            for(int i = 0; i < n ; i ++){
                a[i][j] = cnt ++ ;
            }
        }
        int m_ = cnt ;
        kuhn k(n_, m_);
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0; j < m ; j++) if(b[i][j] == '.'){
                if(i > 0 && j > 0 && b[i - 1][j - 1] == '.') k.edge(a[i][j], a[i - 1][j - 1], j & 1) ;
                if(j > 0 && b[i][j - 1] == '.') k.edge(a[i][j], a[i][j - 1], j & 1) ;
                if(i > 0 && j < m - 1 && b[i - 1][j + 1] == '.') k.edge(a[i][j], a[i - 1][j + 1], j & 1);
                if(j < m - 1 && b[i][j + 1] == '.') k.edge(a[i][j], a[i][j + 1], j & 1) ;
            }
        }
        int ans = 0 ;
        for(int i = 0 ; i < n ; i ++) for(int j = 0 ; j < m ; j ++) ans += (b[i][j] == '.');        
        return ans - k.max_matching() ;
    }
};