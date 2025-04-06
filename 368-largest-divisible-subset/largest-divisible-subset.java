class Solution {
    public List<Integer> largestDivisibleSubset(int[] a) {
        Arrays.sort(a);
        int n = a.length ;
        int[] dp = new int[n];
        int mx = 1 ;
        for(int i = 0 ; i < n ; i ++){
            dp[i] = 1 ;
            for(int j = 0 ; j < i ; j ++){
                if(a[i] % a[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    mx = Math.max(dp[i], mx);
                }
            }
        }
        List<Integer> ans = new ArrayList<>();
        int prv = -1 ;
        for(int i = n - 1; i >= 0 ; i --){
            if(dp[i] == mx && (prv == -1 || prv % a[i] == 0)){
                mx -- ;
                prv = a[i] ;
                ans.add(a[i]); 
            }
        }
        return ans ;
    }
}