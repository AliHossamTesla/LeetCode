class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& a) {
        set<int>ans ;
        int n = a.size() ;
        for(int i = 0 ; i < n ; i ++){
            for(int j = i + 1 ; j < n ; j ++){
                for(int k = j + 1 ; k < n ; k ++){
                    int v[]{a[i] * 100 + a[j] * 10 + a[k],a[i] * 100 + a[k] * 10 + a[j],a[j] * 100 + a[k] * 10 + a[i],a[j] * 100 + a[i] * 10 + a[k],a[k] * 100 + a[i] * 10 + a[j],a[k] * 100 + a[j] * 10 + a[i] };
                    for(int i : v){
                        if(i % 2 == 0 && i > 99){
                            ans.insert(i) ;
                        }
                    }
                }
            }
        }
        vector<int>ret ;
        for(int i : ans) ret.push_back(i) ;
        return ret ;
    }
};