class Solution {
public:
    int maxSubarraySumCircular(vector<int>& a) {
        int pref = 0, ans1 = INT_MAX, mx = 0, mn = 0, ans2 = INT_MIN;
        for(int i : a){
            pref += i ;
            ans1 = min(ans1, pref - mx) ;
            mx = max(mx, pref) ;
            ans2 = max(ans2, pref - mn) ;
            mn = min(mn, pref) ;
        }
        if(ans1 == pref) return ans2 ;
        return max(pref - ans1, ans2) ;
    }
};