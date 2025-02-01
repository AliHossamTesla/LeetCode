class Solution {
    public boolean[] isArraySpecial(int[] a, int[][] q) {
        int n = a.length;
        int[] pref = new int[n + 1];
        for(int i = 1 ; i < n ; i ++){
            if(a[i] % 2 == a[i - 1] % 2){
                pref[i + 1] = 1;
            }
            pref[i + 1] += pref[i];
        }
        int m = q.length;
        boolean[] ans = new boolean[m];
        for(int i = 0 ; i < m ; i ++){
            int f = q[i][0];
            int t = q[i][1];
            ans[i] = (pref[t + 1] - pref[f + 1] == 0);
        }
        return ans ;
    }
}