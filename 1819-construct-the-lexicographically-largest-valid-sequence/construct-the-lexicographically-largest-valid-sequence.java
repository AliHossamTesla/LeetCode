class Solution {
    public int[] constructDistancedSequence(int n) {
        int[] ans = new int[2*n - 1];
        boolean[] vis = new boolean[n + 1];
        calc(0, ans, vis, n);
        return ans ;
    }
    private boolean calc(int i, int[] ans, boolean[] vis, int n){
        if(i == ans.length){
            return true ;
        }
        if(ans[i] != 0) return calc(i + 1, ans, vis, n);
        for(int j = n ; j >= 1 ; j --){
            if(vis[j]) continue ;
            ans[i] = j ;
            vis[j] = true ;
            if(j == 1){
                if(calc(i + 1, ans, vis, n)) return true ;
            }else if(i + j < 2*n - 1 && ans[i + j] == 0){
                ans[i + j] = j ;
                if(calc(i + 1, ans, vis, n)) return true ;
                ans[i + j] = 0 ; 
            }
            ans[i] = 0 ;
            vis[j] = false;
        }
        return false ;
    }
}