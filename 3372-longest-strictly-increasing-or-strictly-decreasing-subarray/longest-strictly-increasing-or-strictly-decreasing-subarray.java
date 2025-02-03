class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int cntI = 1;
        int cntD = 1;
        int ans = 1 ;
        for(int i = 1 ; i < nums.length ; i ++){
            if(nums[i] > nums[i - 1]) cntI ++ ;
            else cntI = 1 ;
            if(nums[i] < nums[i - 1]) cntD ++ ;
            else cntD = 1 ;
            ans = Math.max(ans, Math.max(cntI, cntD));
        }
        return ans ;
    }
}