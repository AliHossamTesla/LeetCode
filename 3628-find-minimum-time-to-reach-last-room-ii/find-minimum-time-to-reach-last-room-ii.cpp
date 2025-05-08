class Solution {
public:
    int minTimeToReach(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size() ;
        vector<vector<int>>dist(n, vector<int>(m, INT_MAX)) ;
        int dx[]{0, 0, -1, 1}, dy[]{1, -1, 0, 0} ;
        priority_queue<array<int, 4>, vector<array<int, 4>>, greater<>>pq ;
        pq.push({0, 0, 0, 0}) ;
        while(!pq.empty()){
            auto [d, x, y, st] = pq.top() ; pq.pop() ;
            if(dist[x][y] <= d) continue ;
            if(x == n - 1 && y == m - 1) return d ;
            dist[x][y] = d ;
            for(int i = 0 ; i < 4 ; i ++){
                int nx = x + dx[i], ny = y + dy[i] ;
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue ;
                pq.push({max(d, a[nx][ny]) + 1 + st, nx, ny, 1 - st}) ;
            }
        }
        return -1 ;
    }
};