class Solution {
    public int minOperations(int[] nums, int k) {
        int[] cnt = new int[105] ;
        int cur = 0 ;
        for(int i : nums){
            if(++cnt[i] == 1) cur ++ ;
        }
        for(int i = 0 ; i < 105 ; i ++){
            if(cnt[i] != 0){
                if(i == k) return cur - 1 ;
                else if(i > k) return cur ;
                else return -1 ;
            }
        }
        return -1 ;
    }
}