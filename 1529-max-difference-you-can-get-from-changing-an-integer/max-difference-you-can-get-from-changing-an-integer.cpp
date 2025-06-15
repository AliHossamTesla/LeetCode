class Solution {
public:
    int maxDiff(int num) {
        int mx = INT_MIN ;
        for(char c = '0' ; c <= '9' ; c ++){
            string a = to_string(num) ;
            for(char & t : a){
                if(t == c){
                    t = '9' ;
                }
            }
            mx = max(mx, stoi(a)) ;
        }
        int mn = INT_MAX ;
        for(char c = '0' ; c <= '9' ; c ++){
            string a = to_string(num) ;
            char sel = a[0] ;
            for(char &t : a){
                if(t == c){
                    t = (c == sel ? '1' : '0') ;
                }
            }
            mn = min(mn, stoi(a)) ;
        }
        return mx - mn ;
    }
};