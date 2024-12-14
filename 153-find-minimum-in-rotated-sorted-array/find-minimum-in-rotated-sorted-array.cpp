class Solution {
public:
    int findMin(vector<int>& a) {
        int l = 0, r = a.size() - 1;
        while(l < r){
            int md = l + (r - l)/2 ;
            if(a[md] > a[r]){
                l = md + 1 ;
            }else{
                r = md;
            }
        }
        return a[l] ;
    }
};