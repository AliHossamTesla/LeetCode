class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans ;
        for(int i = 0 ; i < s.size() ; i += k){
            if(i + k > s.size() && s.size() % k != 0){
                ans.push_back(s.substr(i) + string(k - s.size() % k, fill));
            }else ans.push_back(s.substr(i, k)) ;
        }
        return ans ;
    }
};