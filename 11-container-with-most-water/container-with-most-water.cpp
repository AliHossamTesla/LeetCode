class Solution {
public:
    int maxArea(vector<int>& a) {
        int l = 0, r = a.size() - 1, ans = (min(a[l], a[r]) * (r - l)) ;
        while(l < r){
            if(a[l] > a[r]) r -- ; 
            else l ++ ;
            ans = max(min(a[l], a[r]) * (r - l), ans) ;
        }
        return ans ;
    }
};