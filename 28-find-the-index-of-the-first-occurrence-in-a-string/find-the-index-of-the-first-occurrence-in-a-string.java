class Solution {
    private int KMP(char[] a, int m){
        int n = a.length ;
        int[] pi = new int[n];
        for(int i = 1; i < n ; i ++){
            int j = pi[i - 1] ;
            while(j > 0 && a[i] != a[j]) j = pi[j - 1];
            if(a[i] == a[j]) j ++ ;
            pi[i] = j ;
            if(j == m){
                return i - 2*m ;
            }
        }
        return -1 ;
    }
    public int strStr(String haystack, String needle) {
        int m = needle.length();
        return KMP((needle + '#' + haystack).toCharArray(), m);
    }
}