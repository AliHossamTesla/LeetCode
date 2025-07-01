class Solution {
public:
    int possibleStringCount(string s) {
        int ans = 1 ; 
        for(int i = 0 ; i < s.size() ; i ++){
            int j = i ;
            while(j < s.size() - 1 && s[i] == s[j + 1]) j ++ ;
            ans += (j - i) ;
            i = j ;
        }
        return ans ;
    }
};