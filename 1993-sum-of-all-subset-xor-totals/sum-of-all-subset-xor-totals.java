class Solution {
    public int subsetXORSum(int[] nums) {
        int ans = 0 ;
        for(int i = 1 ; i < (1 << nums.length) ; i ++){
            int cr = 0 ;
            for(int j = 0 ; j < nums.length ; j ++){
                if((i >> j & 1) == 1){
                    cr ^= nums[j];
                }
            }
            ans += cr ;
        }
        return ans ;
    }
}