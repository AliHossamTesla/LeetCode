class Solution {
public:
    int search(vector<int>& a, int t) {
        int l = 0, r = a.size() - 1;
        while(l <= r){
            int md = l + (r - l)/2 ;
            if(t == a[md]) return md ;
            if(a[md] > a[r]){
                if((t > a[md] && t > a[r]) || (t < a[md] && t <= a[r]))
                    l = md + 1 ;
                else r = md - 1;
            }else{
                if(a[r] >= t && a[md] <= t) l = md + 1 ;
                else r = md - 1;
            }
        }
        return -1 ;
    }
};