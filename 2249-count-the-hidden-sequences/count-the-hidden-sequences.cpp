class Solution {
public:
    int numberOfArrays(vector<int>& d, int l, int r) {
        int n = d.size() ;
        vector<long long>a(n + 1) ;
        a[0] = 0 ;
        for(int i = 1 ; i <= n ; i ++){
            a[i] = 1LL * d[i - 1] + a[i - 1] ;
        }
        long long dec = l - *min_element(begin(a), end(a));
        long long mx = l ;
        for(int i : a){
            mx = max(mx, i + dec) ;
        }
        return max(0LL, r - mx + 1) ;
    }
};