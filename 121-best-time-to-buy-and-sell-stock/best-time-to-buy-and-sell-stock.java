class Solution {
    public int maxProfit(int[] prices) {
        int mn = Integer.MAX_VALUE;
        int ans = 0 ;
        for(int i : prices){
            ans = Math.max(ans, i - mn);
            if(i < mn){
                mn = i ;
            }
        }
        return ans ;
    }
}