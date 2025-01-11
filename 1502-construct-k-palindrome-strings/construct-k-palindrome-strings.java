class Solution {
    public boolean canConstruct(String s, int k) {
        if(s.length() < k) return false;
        if(s.length() == k) return true;

        int[] cnt = new int[26] ;
        for(char i : s.toCharArray()){
            cnt[i - 'a'] ++ ;
        }

        int odd = 0 ;
        for(int i = 0 ; i < 26 ; i ++)
            odd += cnt[i] % 2 ;

        return odd <= k ;
    }
}