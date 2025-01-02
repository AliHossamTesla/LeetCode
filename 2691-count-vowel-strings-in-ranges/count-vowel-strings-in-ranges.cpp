class Solution {
public:
    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& q) {
        vector<int>pref(w.size() + 1), ans;
        string s = "aeiou" ;
        for(int i = 0 ; i < w.size() ; i ++){
            pref[i + 1] = (s.find(w[i][0]) != -1 && s.find(w[i][w[i].size() - 1]) != -1) ;
            pref[i + 1] += pref[i] ;
        }
        for(auto v : q){
            ans.push_back(pref[v[1] + 1] - pref[v[0]]) ;
        }
        return ans ;
    }
};