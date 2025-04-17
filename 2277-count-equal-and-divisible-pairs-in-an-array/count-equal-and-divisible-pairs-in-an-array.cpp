class Solution {
public:
    int countPairs(vector<int>& a, int k) {
        int ans = 0, n = a.size();
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < i ; j ++){
                if((i * j) % k == 0 && a[i] == a[j]) ans ++ ;
            }
        }
        return ans ;
    }
};