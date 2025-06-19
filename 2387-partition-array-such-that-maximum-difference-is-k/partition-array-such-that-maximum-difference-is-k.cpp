class Solution {
public:
    int partitionArray(vector<int>& a, int k) {
        int ans = 0 ;
        sort(begin(a), end(a)) ;
        for(int i = 1, j = 0; i <= a.size() ; i ++){
            if(i == a.size() || a[i] - a[j] > k){
                ans ++ ;
                j = i ;
            }
        }
        return ans ;
    }
};