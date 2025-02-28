class Solution {
    public int maxProfit(int[] p) {
        int ans = 0 ;
        for(int i = 1 ; i < p.length ; i ++){
            ans += Math.max(0, p[i] - p[i - 1]);
        }
        return ans ;
    }
}