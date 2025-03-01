class Solution {
    public int hIndex(int[] c) {
        int[] cnt = new int[1001];
        for(int i : c) cnt[i] ++ ;
        for(int i = 999 ; i >= 0 ; i --) cnt[i] += cnt[i + 1];
        for(int i = 1000 ; i >= 0 ; i --){
            if(cnt[i] >= i){
                return i ;
            }
        }
        return -1 ;
    }
}