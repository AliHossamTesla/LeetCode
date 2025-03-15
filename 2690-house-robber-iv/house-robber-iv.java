class Solution {
    public int minCapability(int[] a, int k) {
        int l = Integer.MAX_VALUE, r = Integer.MIN_VALUE;
        for(int i : a){
            l = Math.min(l, i);
            r = Math.max(r, i);
        }
        while(l <= r){
            int md = l + (r - l)/2 ;
            int cnt = 0 ;
            for(int i = 0 ; i < a.length ; i ++){
                if(a[i] <= md){
                    cnt ++ ;
                    i ++ ;
                }
            }
            if(cnt >= k){
                r = md - 1;
            }else l = md + 1 ;
        }
        return l ;
    }
}