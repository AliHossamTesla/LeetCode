class Solution {
    public int minimumRecolors(String blocks, int k) {
        int ans = k ;
        int cr = 0 ;
        for(int i = 0 ; i < k ; i ++){
            if(blocks.charAt(i) == 'W') cr ++ ;
        }
        ans = cr ;
        for(int i = k ; i < blocks.length() ; i ++){
            if(blocks.charAt(i - k) == 'W') cr -- ;
            if(blocks.charAt(i) == 'W') cr ++ ;
            ans = Math.min(ans, cr);
        }
        return ans ;
    }
}