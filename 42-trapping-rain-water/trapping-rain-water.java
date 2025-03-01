class Solution {
    public int trap(int[] h) {
        int n = h.length ;
        int[] lmx = h.clone();
        int[] rmx = h.clone();
        for(int i = 1 ; i < n ; i ++){
            rmx[n - i - 1] = Math.max(rmx[n - i - 1], rmx[n - i]);
            lmx[i] = Math.max(lmx[i], lmx[i - 1]);
        }
        int ans = 0 ;
        for(int i = 0 ; i < n ; i ++){
            int cr = Math.min(lmx[i], rmx[i]);
            ans += (cr - h[i]);
            System.out.println(i + ": " + (cr - h[i]));
        }
        return ans ;
    }
}