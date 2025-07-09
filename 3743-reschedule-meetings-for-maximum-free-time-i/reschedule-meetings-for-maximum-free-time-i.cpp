class Solution {
public:
    int maxFreeTime(int T, int k, vector<int>& s, vector<int>& e) {
        vector<int>a ;
        int n = s.size(), prv = 0, sum = 0, mx = 0;
        for(int i = 0 ; i < n ; i ++){
            a.push_back(s[i] - prv) ;
            prv = e[i] ;
        }
        a.push_back(T - prv) ;
        for(int i = 0 ; i <= k ; i ++){
            sum += a[i] ;
        }
        mx = sum ;
        for(int i = k + 1 ; i < a.size() ; i ++){
            sum -= a[i - k - 1] ;
            sum += a[i] ;
            mx = max(mx, sum) ;
        }
        return mx ;
    }
};