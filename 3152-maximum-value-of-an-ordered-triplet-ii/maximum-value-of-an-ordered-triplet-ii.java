class Solution {
    public long maximumTripletValue(int[] a) {
        int n = a.length ;
        int[] suf = new int[n + 1] ;
        suf[n] = 0 ;
        for(int i = n - 1; i >= 0 ; i --){
            suf[i] = Math.max(suf[i + 1], a[i]);
        }
        long ans = 0 ;
        int prf = a[0];
        for(int i = 1; i < n - 1 ; i ++){
            ans = Math.max(ans, (prf - a[i]) * 1L * suf[i + 1]);
            prf = Math.max(prf, a[i]);
        }
        return ans ;
    }
}