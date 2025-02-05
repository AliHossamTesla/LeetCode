class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        if(s1.equals(s2)) return true ;
        char[] s = s1.toCharArray();
        int idx = -1 ;
        for(int i = 0 ; i < s.length ; i ++){
            if(s[i] != s2.charAt(i)){
                if(idx == -1){
                    idx = i ;
                }else{
                    char temp = s[i];
                    s[i] = s[idx];
                    s[idx] = temp;
                    return (new String(s)).equals(s2);
                }
            }
        }
        return false ;
    }
}