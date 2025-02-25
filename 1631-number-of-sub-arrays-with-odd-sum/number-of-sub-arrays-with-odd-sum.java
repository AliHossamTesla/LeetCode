class Solution {
    public int numOfSubarrays(int[] arr) {
        long[] cnt = new long[2] ;
        int ans = 0 ;
        int pref = 0;
        cnt[0] = 1;
        for(int i : arr){
            pref += i ;
            ans += cnt[(pref & 1) ^ 1];
            ans %= 1000000007 ;
            cnt[pref & 1] ++ ;
        }
        return ans ;
    }
}