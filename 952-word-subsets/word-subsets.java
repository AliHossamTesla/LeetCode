class Solution {
    public List<String> wordSubsets(String[] words1, String[] words2) {
        int[] cnt = new int[26] ;
        List<String>ans = new ArrayList<>() ;
        // for(int i = 0 ; i < 26 ; i ++) cnt[i] = 0 ;
        for(String s : words2){
            int[] tcnt = new int[26] ;
            for(int i = 0 ; i < s.length() ; i ++){
                tcnt[s.charAt(i) - 'a'] ++ ;
            }
            for(int i = 0 ; i < 26 ; i ++)
                cnt[i] = Math.max(cnt[i], tcnt[i]) ;
        }

        for(String s : words1){
            int[] tcnt = new int[26] ;
            for(int i = 0 ; i < s.length() ; i ++){
                tcnt[s.charAt(i) - 'a'] ++ ;
            }
            boolean ok = true ;
            for(int i = 0 ; i < 26 ; i ++)
                ok &= (tcnt[i] >= cnt[i]) ;
            if(ok) ans.add(s) ;
        }
        return ans ;
    }
}