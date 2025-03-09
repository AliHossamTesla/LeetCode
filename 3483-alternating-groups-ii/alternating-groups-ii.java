class Solution {
    public int numberOfAlternatingGroups(int[] colors, int k) {
        int l = 0, r = 1 ;
        int n = colors.length ;
        int ans = 0 ;
        for(; r < n + k - 1 ; r ++){
            if(colors[(r % n)] == colors[((r - 1) + n)%n]){
                l = r ;
            }
            if((r - l + 1) == k){
                // System.out.println(l + " " + r);
                ans ++ ;
                l ++ ;
            }
        }
        return ans ;
    }
}