class Solution {
public:
    int minimizeMax(vector<int>& a, int p) {
        if(!p) return 0 ;
        sort(begin(a), end(a)) ;
        int l = 0, r = a.back() - a[0] ;
        auto can = [&](int x){
            int cnt = 0 ;
            for(int i = 0 ; i < a.size() - 1 ; i ++){
                if(a[i + 1] - a[i] <= x){
                    cnt ++ ;
                    i ++ ;
                }
            }
            return cnt >= p ;
        };
        while(l <= r){
            int md = l + (r - l)/2 ;
            if(can(md)) r = md - 1 ;
            else l = md + 1 ;
        }
        return l ;
    }
};