class Solution {
public:
    string largestGoodInteger(string s) {
        int mx = -1 ;
        for(int i = 0 ; i < s.size() - 2 ; i ++){
            if(mx < (s[i] - '0') && s[i] == s[i + 1] && s[i] == s[i + 2])
            mx = s[i] - '0'  ;
        }
        if(mx == -1) return "" ;
        return string(3, char(mx + '0')) ;
    }
};