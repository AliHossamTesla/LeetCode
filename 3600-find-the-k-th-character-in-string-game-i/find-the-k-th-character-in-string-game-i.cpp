class Solution {
public:
    char kthCharacter(int k) {
        string s = "a" ;
        while(s.size() < k){
            string t = s ;
            for(char &c : t){
                c = 'a' + (c - 'a' + 1)%26 ;
            }
            s += t ;
        }
        return s[k - 1] ;
    }
};