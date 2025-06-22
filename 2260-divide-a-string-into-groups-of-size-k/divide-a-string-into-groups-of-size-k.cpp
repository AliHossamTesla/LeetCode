class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int need = k - s.size() % k ;
        if(need != k) s += string(need, fill) ;
        vector<string>ans ;
        for(int i = 0 ; i < s.size() ; i += k){
            ans.push_back(s.substr(i, k)) ;
        }
        return ans ;
    }
};