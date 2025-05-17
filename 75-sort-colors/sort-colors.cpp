class Solution {
public:
    void sortColors(vector<int>& a) {
        int l = 0, r = a.size() - 1, md = 0 ;
        while(md <= r){
            if(a[md] == 0){
                swap(a[md++], a[l ++]) ;
            }else if(a[md] == 1) md ++ ;
            else swap(a[md], a[r--]) ;
        }
    }
};