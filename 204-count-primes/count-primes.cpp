class Solution {
public:
    int countPrimes(int n) {
        if(n <= 1) return 0 ;
        int N = n + 1 ;
        int spf[n + 1];
        spf[1] = 1;
        for (int i = 2; i < N; i++) spf[i] = i;
        for (int i = 4; i < N; i += 2) spf[i] = 2;
        for (int i = 3; i * i < N; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < N; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
        int ans = 0 ;
        for(int i = 2 ;i < n ; i ++) ans += spf[i] == i ;
        return ans ;
    }
};