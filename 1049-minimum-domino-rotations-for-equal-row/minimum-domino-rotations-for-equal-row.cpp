class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int cnt[7] = {}, lft[7] = {}, rgt[7] = {};
        int n = tops.size() ;
        for(int i = 0 ; i < n ;i ++){
            cnt[tops[i]] ++ ;
            lft[bottoms[i]] ++ ;
            if(tops[i] != bottoms[i]) cnt[bottoms[i]] ++ ;
            rgt[tops[i]] ++ ;
        }
        int ans = -1 ;
        for(int i = 1 ; i <= 6 ; i ++){
            if(cnt[i] == n){
                ans = min(max(0, n - rgt[i]), max(0, n - lft[i])) ;
            }
        }
        return ans ;
    }
};