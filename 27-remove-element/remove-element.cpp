class Solution {
public:
    int removeElement(vector<int>& a, int val) {
        int l = 0, r = a.size() - 1, ans = 0 ;
        while(l <= r){
            if(a[l] == val){
                while(l < r && a[r] == val) r -- ;
                swap(a[l], a[r]) ;
             }
            if(a[l] != val) ans ++ ;
            l ++ ;           
        }
        return ans ;
    }
};