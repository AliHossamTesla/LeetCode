class Solution {
    int[] dp ;
    public int numDecodings(String s) {
        char[] a = s.toCharArray();
        int n = s.length() ;
        int prv = 1 ;
        int prv2 = 0 ;
        for(int i = 1 ; i <= n ; i ++){
            int cr = 0 ;
            if(a[i - 1] != '0') cr = prv;
            if(i > 1 && (a[i - 2] == '1' || (a[i - 2] == '2' && a[i - 1] <= '6')))
                cr += prv2;
            prv2 = prv ;
            prv = cr ;
        }
        return prv;
    }
}