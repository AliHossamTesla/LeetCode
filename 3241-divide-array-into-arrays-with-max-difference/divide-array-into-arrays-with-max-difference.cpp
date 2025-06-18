class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& b, int k) {
        sort(begin(b), end(b)) ;
        int n = b.size() ;
        vector<vector<int>>a(n/3) ;
        for(int i = 0 ;i < n ; i ++) a[i/3].push_back(b[i]) ;
        for(int i = 0 ; i < n/3 ; i ++) if(a[i][2] - a[i][0] > k) return vector<vector<int>>();
        return a ;
    }
};