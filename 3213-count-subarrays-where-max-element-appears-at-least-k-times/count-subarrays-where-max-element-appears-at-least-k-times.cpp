class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        long long mx = *max_element(begin(a), end(a)), n = a.size(), ans = 0, l = 0, cnt = 0;
        for(int r = 0 ; r < n ; r ++){
            if(a[r] == mx) cnt ++ ;
            while(cnt >= k){
                if(a[l] == mx) cnt -- ;
                l ++ ;
                ans += n - r ;
            }
        }
        return ans ;
    }
};