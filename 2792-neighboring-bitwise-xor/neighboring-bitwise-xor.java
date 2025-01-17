class Solution {
    public boolean doesValidArrayExist(int[] d) {
        // int n = d.length;
        // int[] ans = new int[n];
        // for(int i = 0 ; i < n ; i ++){
        //     if(i == n - 1) ans[i] = (d[i] ^ ans[0]) ;
        //     else ans[i] = (d[i] ^ d[i + 1]) ;
        //     System.out.print(ans[i] + " ");
        // }
        // for(int i = 0 ; i < n ; i ++) 
        //     if((ans[i] ^ ans[(i + 1) % n]) != d[i]) return false ;
        int xr = 0 ;
        for(int i : d) xr ^= i ;
        return xr == 0;
    }
}