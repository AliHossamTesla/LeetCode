class Solution {
    public int minZeroArray(int[] a, int[][] q) {
        int l = 0, r = q.length, ans = -1 ;
        int n = a.length ;
        while(l <= r){
            int md = l + (r - l)/2 ;
            int[] cr = new int[n + 1];
            for(int i = 0 ; i < md ; i ++){
                cr[q[i][0]] += q[i][2] ;
                cr[q[i][1] + 1] -= q[i][2] ;
            }
            boolean ok = (cr[0] >= a[0]);
            for(int i = 1 ; i < n ; i ++){
                cr[i] += cr[i - 1];
                ok &= (cr[i] >= a[i]);
            }
            if(ok){
                ans = md ;
                r = md - 1;
            }else l = md + 1;
        }
        return ans ;
    }
}