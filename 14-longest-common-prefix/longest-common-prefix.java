class Solution {
    public String longestCommonPrefix(String[] strs) {
        int l = 0 ;
        for(; l < min(strs); l ++){
            boolean ok = true ;
            for(String s : strs){
                ok &= (s.charAt(l) == strs[0].charAt(l));
            }
            if(!ok){
                break ;
            }
        }
        return strs[0].substring(0, l);
    }
    private int min(String[] strs){
        int mn = Integer.MAX_VALUE;
        for(String s : strs){
            mn = Math.min(s.length(), mn);
        }
        return mn ;
    }

}