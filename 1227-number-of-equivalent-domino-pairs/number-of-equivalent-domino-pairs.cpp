const int LG = 9;
int cnt[LG][LG] ;
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for(int i = 0 ; i < LG ; i ++)
            for(int j = 0 ; j < LG ; j ++) cnt[i][j] = 0 ;
        int ans = 0 ;
        for(auto v : dominoes){
            int i = v[0], j = v[1] ;
            if(i > j) swap(i, j) ;
            i -- ; j -- ;
            ans += cnt[i][j] ++ ;
        }
        return ans ;
    }
};