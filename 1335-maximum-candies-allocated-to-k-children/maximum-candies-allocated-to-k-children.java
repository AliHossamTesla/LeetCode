class Solution {
    public int maximumCandies(int[] candies, long k) {
        long l = 1, r = 10_000_000 ;
        while(l <= r){
            long md = l + (r - l)/2 ;
            long cnt = 0 ;
            for(int i : candies){
                cnt += (i/md);
            }
            if(cnt >= k){
                l = md + 1;
            }else r = md - 1;
        }
        return (int)r ;
    }
}