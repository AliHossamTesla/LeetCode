class Solution {
    public int hIndex(int[] c) {
        int[] cnt = new int[1001];
        for(int i : c) cnt[i] ++ ;
        if(cnt[1000] >= 1000) return 1000 ;
        for(int i = 999 ; i >= 0 ; i --){
            cnt[i] += cnt[i + 1];
            if(cnt[i] >= i){
                return i ;
            }
        }
        return -1 ;
    }
}