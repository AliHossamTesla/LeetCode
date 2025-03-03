class Solution {
    int[] dp ;
    int n ;
    public boolean validPartition(int[] nums) {
        n = nums.length;
        dp = new int[n];
        Arrays.fill(dp, -1);
        return calc(0, nums) == 0 ? false : true ;
    }
    private int calc(int i, int[] a){
        if(i == n) return 1 ;
        if(dp[i] != -1) return dp[i] ;
        dp[i] = 0 ;
        if(i < n - 1 && a[i] == a[i + 1] && calc(i + 2, a) == 1)
            dp[i] = 1 ;
        if(i < n - 2 && a[i] == a[i + 1] && a[i] == a[i + 2] && calc(i + 3, a) == 1)
            dp[i] = 1 ;
        if(i < n - 2 && a[i] == a[i + 1] - 1 && a[i] == a[i + 2] - 2 && calc(i + 3, a) == 1)
            dp[i] = 1 ;
        return dp[i] ;
    }
}