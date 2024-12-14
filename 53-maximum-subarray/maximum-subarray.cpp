class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int mn = 0, ans = INT_MIN, pref = 0 ;
        for(int i : a){
            pref += i ;
            ans = max(ans, pref - mn) ;
            mn = min(mn, pref) ;
        }
        return ans ;
    }
};