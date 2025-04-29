class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        long long mx = *max_element(begin(a), end(a)), n = a.size(), ans = 0;
        vector<long long>idx ;
        idx.push_back(-1) ;
        for(int i = 0 ; i < n ; i ++){
            if(a[i] == mx) idx.push_back(i) ;
        }
        if(idx.size() < k) return 0 ;
        for(int i = 1 ; i <=  idx.size() - k ; i ++){
            ans += (idx[i] - idx[i - 1]) * (n - idx[i + k - 1]);
        }
        return ans ;
    }
};