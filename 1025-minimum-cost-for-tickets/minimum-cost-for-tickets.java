class Solution {
    int[][] dp ;
    public int mincostTickets(int[] days, int[] costs) {
        dp = new int[days.length][365];
        for(int i = 0 ; i < days.length ; i ++)
            for(int j = 0 ; j < 365 ; j ++) dp[i][j] = -1 ;
        return calc(0, 0, days, costs);
    }
    private int calc(int i, int to, int[] days, int[] costs){
        if(i == days.length){
            return 0 ;
        }
        if(to >= 365) return 0 ;
        if(dp[i][to] != -1) return dp[i][to];
        if(to >= days[i]) return dp[i][to] = calc(i + 1, to, days, costs);
        else{
            dp[i][to] = 1_000_000_000;
            for(int j = 0 ; j < 3 ; j ++){
                int c = costs[j];
                int v ;
                if(j == 0) v = 1 ;
                else if(j == 1) v = 7 ;
                else v = 30 ;
                dp[i][to] = Math.min(dp[i][to], c + calc(i + 1, days[i] + v - 1, days, costs));
            }
            return dp[i][to];
        }
    }
}