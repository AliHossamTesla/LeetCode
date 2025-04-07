class Solution {
    int[][] dp ;
    private int calc(int[] a, int i, int sm){
        if(sm == 0) return 1 ;
        if(i == a.length) return 0 ;
        if(sm < 0) return 0 ;
        if(dp[i][sm] != -1) return dp[i][sm] ;
        if(calc(a, i + 1, sm - a[i]) == 1) dp[i][sm] = 1 ;
        else if(calc(a, i + 1, sm) == 1) dp[i][sm] = 1;
        else dp[i][sm] = 0 ;
        return dp[i][sm] ;
    }
    public boolean canPartition(int[] nums) {
        int sum = 0 ;
        for(int i : nums) sum += i ;
        if(sum % 2 != 0) return false ;
        dp = new int[nums.length][sum/2 + 1] ;
        for(int i = 0;i < nums.length; i ++) Arrays.fill(dp[i], -1) ;
        return calc(nums, 0, sum/2) == 1;
    }
}