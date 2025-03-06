class Solution {
    public int findGoodStrings(int n, String s1, String s2, String evil) {
        long[] dp = new long[1 << 17];
        Arrays.fill(dp, -1);
        return (int)calc(0, 0, true, true, n, s1.toCharArray(), s2.toCharArray(), evil.toCharArray(), KMP(evil.toCharArray()), dp);
    }

    private long calc(int i, int i_e, boolean l, boolean r, int n, char[] s1, char[] s2, char[] evil, int[] pi, long[] dp){
        if(i_e == evil.length) return 0 ;
        if(i == n) return 1 ;

        int key = getKey(i, i_e, l, r);
        if(dp[key] != -1) return dp[key];
        dp[key] = 0 ;
        char st = (l ? s1[i] : 'a');
        char ed = (r ? s2[i] : 'z');
        for(char c = st ; c <= ed ; c ++){
            int j = i_e ;
            while(j > 0 && c != evil[j]) j = pi[j - 1];
            if(c == evil[j]) j ++ ;
            dp[key] += calc(i + 1, j, l && (c == st), r && (c == ed), n, s1, s2, evil, pi, dp);
            dp[key] %= 1_000_000_007 ;
        }
        return dp[key];
    }

    private int getKey(int n, int m, boolean b1, boolean b2) {
        // Need 9 bits store n (2^9=512), 6 bits store m (2^6=64), 1 bit store b1, 1 bit store b2
        return (n << 8) | (m << 2) | ((b1 ? 1 : 0) << 1) | (b2 ? 1 : 0);
    }
    
    private int[] KMP(char[] s){
        int n = s.length;
        int[] pi = new int[n];
        for(int i = 1 ; i < n ; i ++){
            int j = pi[i - 1];
            while(j > 0 && s[i] != s[j]) j = pi[j - 1];
            if(s[i] == s[j]) j ++ ;
            pi[i] = j ;
        }
        return pi ;
    }
}