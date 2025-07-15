class Solution {
public:
    bool isValid(string s) {
        if(s.size() < 3) return false ;
        bool vis[26] = {} ;
        vis[0] = vis['e' - 'a'] = vis['i' - 'a'] = vis['o' - 'a'] = vis['u' - 'a'] = 1 ;
        int cnt = 0, n = s.size();
        for(char c : s){
            if(c >= '0' && c <= '9') n -- ;
            else if(c >= 'a' && c <= 'z') cnt += vis[c - 'a'] ;
            else if(c >= 'A' && c <= 'Z'){
                cnt += vis[c - 'A'] ;
            }else return false ;
        }
        return cnt > 0 && n > cnt ;
    }
};