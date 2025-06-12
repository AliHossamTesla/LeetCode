class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = INT_MIN ;
        for(int i = 0 ; i < nums.size() ; i ++){
            ans = max(ans, abs(nums[i] - nums[(i + 1) % nums.size()])) ;
        }
        return ans ;
    }
};