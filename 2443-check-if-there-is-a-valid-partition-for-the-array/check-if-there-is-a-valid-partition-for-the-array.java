class Solution {
    public boolean validPartition(int[] a) {
        int n = a.length;
        boolean[] dp = new boolean[n + 1];
        dp[0] = true;
        for(int i = 0 ; i < n - 1; i ++){
            if(a[i] == a[i + 1] && dp[i]) dp[i + 2] = true ;
            if(i < n - 2){
                if(a[i] == a[i + 1] && a[i] == a[i + 2] && dp[i]) dp[i + 3] = true ;
                if(a[i] == a[i + 1] - 1 && a[i] == a[i + 2] - 2 && dp[i])
                    dp[i + 3] = true ;
            }
        }
        return dp[n];
    }
}