class Solution {
    public long coloredCells(int n) {
        long ans = 1 ;
        for(int i = 2, j = 4; i <= n ; i ++, j += 4){
            ans += j ;
        }
        return ans;
    }
}