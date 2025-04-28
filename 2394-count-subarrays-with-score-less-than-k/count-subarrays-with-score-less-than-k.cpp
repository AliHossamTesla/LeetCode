class Solution {
public:
    long long countSubarrays(vector<int>& a, long long k) {
        long long sum = 0, ans = 0 ;
        for(int i = 0, j = 0;i < a.size() ; i ++){
            sum += a[i] ;
            while(sum * (i - j + 1) >= k) sum -= a[j ++];
            // cout << j << " " << i << '\n' ;
            if(j <= i) ans += (i - j + 1) ;
        }
        return ans ;
    }
};