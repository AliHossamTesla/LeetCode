class Solution {
    public boolean rotateString(String s, String goal) {
        if(s.length() != goal.length()) return false ;
        char[] a = (goal + '#' + s + s).toCharArray();
        int n = a.length ;
        int[] pi = new int[n];
        for(int i = 1 ;i < n ; i ++){
            int j = pi[i - 1];
            while(j > 0 && a[i] != a[j]) j = pi[j - 1] ;
            if(a[i] == a[j]) j ++ ;
            if(j == goal.length()) return true ;
            pi[i] = j ;
        }
        return false ;
    }
}