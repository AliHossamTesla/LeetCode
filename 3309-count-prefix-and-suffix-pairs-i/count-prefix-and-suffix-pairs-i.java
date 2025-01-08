class Solution {
    public int countPrefixSuffixPairs(String[] w) {
        int ans = 0 ;
        for(int i = 0 ; i < w.length ; i ++){
            for(int j = i + 1 ; j < w.length ; j ++){
                if(chk(w[i], w[j])) ans ++ ;
            }
        } 
        
        return ans;
    }
    public static boolean chk(String s, String t){
        if(s.length() > t.length()) return false;
        for(int i = 0 ; i < s.length() ; i ++){
            if(s.charAt(i) != t.charAt(i)) return false;
        }
        for(int i = 0 ; i < s.length() ; i ++){
            if(s.charAt(s.length() - i - 1) != t.charAt(t.length() - i - 1)) return false;
        }
        return true;
    }
}