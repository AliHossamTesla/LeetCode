class Solution {
public:
    int maxDifference(string s) {
        int cnt[26] = {} ;
        for(auto c : s) cnt[c - 'a'] ++ ;
        sort(begin(cnt), end(cnt)) ;
        int l = 0, r = 25 ; 
        while(cnt[r] % 2 == 0) r -- ;
        while(cnt[l] % 2 || !cnt[l]) l ++ ;
        return cnt[r] - cnt[l] ;
    }
};