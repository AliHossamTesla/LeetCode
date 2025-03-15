class Solution {
    public int minCapability(int[] nums, int k) {
        int l = Integer.MAX_VALUE, r = Integer.MIN_VALUE;
        for(int i : nums){
            l = Math.min(l, i);
            r = Math.max(r, i);
        }
        while(l <= r){
            int md = l + (r - l)/2 ;
            if(ok(nums, md, k)){
                r = md - 1;
            }else l = md + 1 ;
        }
        return l ;
    }
    private boolean ok(int[] a, int x, int k){
        int cnt = 0 ;
        for(int i = 0 ; i < a.length ; i ++){
            if(a[i] <= x){
                cnt ++ ;
                i ++ ;
            }
        }
        return cnt >= k ;
    }
}