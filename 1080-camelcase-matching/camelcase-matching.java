class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        List<Boolean> ans = new ArrayList<>();
        for(String s : queries){
            int i = 0 ;
            boolean ok = true ;
            for(int j = 0 ; j < s.length() ; j ++){
                if(i < pattern.length() && s.charAt(j) == pattern.charAt(i)){
                    i ++ ;
                }else if(s.charAt(j) >= 'a' && s.charAt(j) <= 'z') continue ;
                else{
                    ok = false ;
                    break ;
                }
            }
            ok &= (i == pattern.length()) ;
            ans.add(ok);
        }
        return ans ;
    }
}