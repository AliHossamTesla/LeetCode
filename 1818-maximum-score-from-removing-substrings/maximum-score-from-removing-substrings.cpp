class Solution {
public:
    int maximumGain(string s, int x, int y) {
       if(x > y){
            deque<char>st, st1;
            int ans = 0 ;
            for(char c : s){
                if(st.size() && st.back() == 'a' && c == 'b')
                    ans += x, st.pop_back() ;
                else st.push_back(c) ;
            }
            for(char c : st){
                if(st1.size() && st1.back() == 'b' && c == 'a') 
                    ans += y, st1.pop_back() ;
                else st1.push_back(c) ;
            }
            return ans ;
       }else{
            deque<char>st, st1;
            int ans = 0 ;
            for(char c : s){
                if(st1.size() && st1.back() == 'b' && c == 'a') 
                    ans += y, st1.pop_back() ;
                else st1.push_back(c) ;
            }
            for(char c : st1){
                if(st.size() && st.back() == 'a' && c == 'b') 
                    ans += x, st.pop_back() ;
                else st.push_back(c) ;
            }
            return ans ;
       } 
    }
};