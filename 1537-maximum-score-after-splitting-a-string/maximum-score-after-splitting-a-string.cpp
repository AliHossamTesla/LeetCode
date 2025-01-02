class Solution {
public:
    int maxScore(string s) {
        int zr = 0, on = count(begin(s), end(s), '1'), ans = INT_MIN ;
        for(int i = 0 ; i < s.size() - 1 ; i ++){
            zr += (s[i] == '0') ;
            on -= (s[i] == '1') ;
            ans = max(ans, zr + on) ;
        }
        return ans ;
    }
};