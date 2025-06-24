class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& a, int k, int t) {
        vector<int>ans ;
        for(int i = 0 ; i < a.size() ; i ++){
            for(int j = 0 ; j < a.size() ; j ++){
                if(abs(i - j) <= t && a[j] == k){
                    ans.push_back(i) ;
                    break ;
                }
            }
        }
        return ans ;
    }
};