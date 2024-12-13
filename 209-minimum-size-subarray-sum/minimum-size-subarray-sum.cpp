class Solution {
public:
    int minSubArrayLen(int t, vector<int>& a) {
        int n = a.size() ;
        
        int ans = INT_MAX, r = 0, sum = 0 ;
        for(int l = 0 ; l < n ; l ++){
            while(r < n && sum < t){
                sum += a[r ++] ;
            }
            if(sum >= t) ans = min(ans, r - l) ;
            sum -= a[l] ;
        }
        return ans < INT_MAX ? ans : 0 ;
    }
};