class Solution {
public:
    bool isPalindrome(string s) {
        string t  ;
        for(auto c : s){
            if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) t.push_back(c) ;
            else if(c >= 'A' && c <= 'Z') t.push_back(char(c - 'A' + 'a')) ; 
        }
        cout << t << '\n' ;
        int n = t.size() ;
        for(int i = 0 ; i < n/2 ; i ++){
            if(t[i] != t[n - i - 1]) return false ;
        }
        return true ;
    }
};