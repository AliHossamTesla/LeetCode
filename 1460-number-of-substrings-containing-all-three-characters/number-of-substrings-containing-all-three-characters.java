class Solution {
    public int numberOfSubstrings(String s) {
        char[] a = s.toCharArray();
        int[] cnt = new int[3];
        int ans = 0 ;
        for(int r = 0, l = 0; r < a.length ; r++){
            cnt[a[r] - 'a'] ++ ;
            while(cnt[0] >= 1 && cnt[1] >= 1 && cnt[2] >= 1){
                ans += (a.length - r);
                cnt[a[l++] - 'a'] -- ;
            }
        }
        return ans ;
    }
}