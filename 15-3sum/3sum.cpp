class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size() ;
        sort(begin(a), end(a)) ;
        vector<vector<int>>ans;
        
        for(int i = 0 ; i < n ; i ++){
            
            if(i && a[i] == a[i - 1]) continue;
            
            int l = i + 1, r = n - 1, trg = -a[i];
            while(l < r){
                if(a[l] + a[r] == trg){
                    ans.push_back({a[l], a[r], a[i]}) ;
                    
                    l ++ ; r -- ;
                    while(l < r && a[l] == a[l - 1]) l ++ ;
                    while(l < r && a[r] == a[r + 1]) r -- ;
                }else if(a[l] + a[r] > trg) r -- ;
                else l ++ ;
                
            }
        }

        return ans ;
    }
};