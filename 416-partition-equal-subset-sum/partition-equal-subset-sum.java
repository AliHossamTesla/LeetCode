class Solution {
    public boolean canPartition(int[] a) {
        int sum = 0 ;
        for(int i : a) sum += i ;
        if(sum % 2 != 0) return false ;
        int n = a.length;
        sum /= 2;
        boolean[] dp = new boolean[sum + 1] ;
        dp[0] = true ;
        for(int i = 0 ; i < n ; i ++){
            boolean[] ndp = dp.clone() ;
            for(int s = a[i] ; s <= sum ; s ++){
                ndp[s] |= dp[s - a[i]] ;
            }
            dp = ndp ;
        }
        return dp[sum] ;
    }
}