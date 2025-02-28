class Solution {
    public boolean canJump(int[] a) {
        int mx = a[0] ;
        for(int i = 1 ; i < a.length ; i ++){
            if(mx == 0){
                return false ;
            }
            mx -- ;
            mx = Math.max(mx, a[i]);
        }
        return true ;
    }
}