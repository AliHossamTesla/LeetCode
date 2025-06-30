class Solution {
public:
    int findLHS(vector<int>& a) {
        unordered_map<int, int>mp ;
        for(int i : a) mp[i] ++ ;
        int ans = 0 ;
        for(auto it : mp)if(mp.contains(it.first - 1)){
            ans = max(ans, it.second + mp[it.first - 1]) ;
        }
        return ans ;
    }
};