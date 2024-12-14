class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int ans = 0 , n = p.size();
        for(int i = 0 ; i < n ; i ++){
            for(int j = i + 1 ; j < n ; j ++){
                int cnt = 0 ;
                for(int k = 0 ; k < n ; k ++){
                    int x1 = p[i][0], y1 = p[i][1], x2 = p[j][0], y2 = p[j][1], x3 = p[k][0], y3 = p[k][1] ;
                    if ((y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1))
                        cnt++;
                }
                ans = max(ans, cnt) ;
            }
        }
        map<int,int>mp_x, mp_y;
        for(auto v : p){
            int x = v[0], y = v[1] ;
            mp_x[x] ++ ;
            mp_y[y] ++ ;
            ans = max({ans, mp_x[x], mp_y[y]}) ;
        }
        return ans ;
    }
};