class Solution {
public:
    vector<int> searchRange(vector<int>& a, int t) {
        int l = 0, r = a.size() - 1;
        vector<int>ans(2);
        while(l <= r){
            int md = l + (r - l)/2 ;
            if(a[md] <= t) l = md + 1 ;
            else r = md - 1 ;
        }
        if(r < 0 || a[r] != t) return {-1, -1} ; 
        ans[1] = r ;
        l = 0, r = a.size() - 1;
        while(l <= r){
            int md = l + (r - l)/2 ;
            if(a[md] >= t) r = md - 1 ;
            else l = md + 1;
        }
        ans[0] = l ;
        return ans ;
    }
};