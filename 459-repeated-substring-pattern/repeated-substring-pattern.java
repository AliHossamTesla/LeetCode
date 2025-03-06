class Solution {
    public boolean repeatedSubstringPattern(String s) {
        char[] a = s.toCharArray();
        int n = a.length ;
        int[] pi = new int[n];
        for(int i = 1 ; i < n ; i ++){
            int j = pi[i - 1];
            while(j > 0 && a[i] != a[j]) j = pi[j - 1];
            if(a[i] == a[j]) j ++ ;
            pi[i] = j ;
        }
        return (n % (n - pi[n - 1]) == 0 && pi[n - 1] != 0) ;
    }
}