class Solution {
    public int[] productExceptSelf(int[] nums) {
        int prod = 1 ;
        int cnt0 = -1 ;
        int n = nums.length;
        for(int i = 0 ; i < n ; i ++){
            if(nums[i] != 0) prod *= nums[i] ;
            else{
                if(cnt0 == -1) cnt0 = i ;
                else return new int[n];
            }
        }
        int[] ans = new int[n];
        if(cnt0 != -1){
            ans[cnt0] = prod;
            return ans ;
        }
        for(int i = 0 ; i < n ; i ++){
            ans[i] = prod/nums[i];
        }
        return ans ;
    }
}