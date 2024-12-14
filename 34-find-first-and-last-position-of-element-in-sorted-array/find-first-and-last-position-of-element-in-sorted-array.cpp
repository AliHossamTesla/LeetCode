class Solution {
public:
    vector<int> searchRange(vector<int>& a, int t) {
        int l = 0, r = a.size() - 1;
        while(l <= r){
            int md = l + (r - l)/2 ;
            if(a[md] == t){
                int L = md - 1, R = md + 1 ;
                while(L >= 0 && a[L] == t) L -- ;
                while(R < a.size() && a[R] == t) R ++ ;
                return {L + 1, R - 1} ;
            }
            if(a[md] < t) l = md + 1 ;
            else r = md - 1 ;
        }
        return {-1, -1} ; 
    }
};