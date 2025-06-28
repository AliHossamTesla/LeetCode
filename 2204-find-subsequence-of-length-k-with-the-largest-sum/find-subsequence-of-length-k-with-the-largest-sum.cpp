class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<array<int, 2>>a;
        for(int i = 0 ; i < nums.size() ; i ++) a.push_back({nums[i], i}) ;
        sort(begin(a), end(a)) ;
        vector<array<int, 2>>b ;
        for(int i = a.size() - k ; i < a.size() ; i ++){
            b.push_back({a[i][1], a[i][0]}) ;
        }
        sort(begin(b), end(b)) ;
        vector<int>ans ;
        for(auto [_, v] : b) ans.push_back(v) ;
        return ans ;
    }
};