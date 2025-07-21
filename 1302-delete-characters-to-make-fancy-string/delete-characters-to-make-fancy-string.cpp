class Solution {
public:
    string makeFancyString(string s) {
        string t ;
        for(char c : s){
            if(t.size() >= 2 && t.back() == c && t[t.size() - 2] == c)
                continue ;
            t.push_back(c) ;
        }
        return t ;
    }
};