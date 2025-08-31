class Solution {
    public int reverse(int y) {
        boolean sgn = false ;
        long x = y ;
        if(x < 0){
            sgn = true ;
            // System.out.println("here") ;
            x *= -1 ;
        }
        // System.out.println(x) ;
        StringBuilder s = new StringBuilder(Long.toString(x)) ;
        s = s.reverse() ;
        long ans = (Long.parseLong(s.toString()))  ;
        if(ans > (1L << 31) - (sgn ? 0 : 1)) return 0 ;
        return (sgn ? -1 : 1) * (int)ans;
    }
}