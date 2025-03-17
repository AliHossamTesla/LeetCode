class Solution {
    public boolean divideArray(int[] nums) {
        int[] cnt = new int[501] ;
        int ct = 0 ;
        for(int i : nums){
            cnt[i] ++ ;
        }
        for(int i = 0 ; i < 501 ; i ++) if(cnt[i] % 2 != 0) return false ;
        return true ;
    }
}