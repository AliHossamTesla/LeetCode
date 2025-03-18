class Solution {
    public int longestNiceSubarray(int[] a) {
        int prf = 0, coll = 0, ans = 0;
        for(int i = 0, j = 0; i < a.length ; i ++){
            coll ^= a[i] ;
            prf += ct(a[i]);
            while(ct(coll) != prf){
                prf -= ct(a[j]);
                coll ^= a[j] ;
                j ++ ;
            }
            ans = Math.max(ans, i - j + 1) ;
        }
        return ans ;
    }

    private int ct(int n){
        return Integer.bitCount(n); 
    }
}