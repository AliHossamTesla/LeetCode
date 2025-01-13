class Solution {
    public int minimumLength(String s) {
        int[] cnt = new int[26] ;
        for(char c : s.toCharArray()){
            cnt[c - 'a'] ++ ;
        }
        int ans = 0 ;
        for(int i = 0 ; i < 26 ; i ++){
            System.out.println(cnt[i]) ;
            if(cnt[i] >= 3){
                if(cnt[i] % 2 == 0) ans += 2 ;
                else ans += 1 ;
            }
            else ans += cnt[i] ;
        }
        return ans ;
    }
}