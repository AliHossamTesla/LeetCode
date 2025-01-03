class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long rsum = accumulate(begin(nums), end(nums), 0LL), lsum = 0, ans = 0 ;
        for(int i = 0 ; i < nums.size() - 1 ; i ++){
            lsum += nums[i];
            rsum -= nums[i] ;
            if(lsum >= rsum)
                ans ++ ;
        }
        return ans;
    }
};