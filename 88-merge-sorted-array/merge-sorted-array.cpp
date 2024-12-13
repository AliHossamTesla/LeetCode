class Solution {
public:
    void merge(vector<int>& a, int n, vector<int>& b, int m) {
        int l = n - 1, r = m - 1 ;
        for(int i = n + m - 1 ; i >= 0 ; i --){
            if(l < 0){
                a[i] = b[r--] ;
            }else if(r < 0){
                a[i] = a[l--];
            }else{
                if(a[l] > b[r]) a[i] = a[l--];
                else a[i] = b[r--];
            }
        }
    }
};