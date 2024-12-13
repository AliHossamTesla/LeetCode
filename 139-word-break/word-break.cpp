class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size() ;
        vector<bool>dp(n + 1, false) ;
        dp[0] = 1;
        unordered_set<string>st ;
        for(auto c : wordDict)
            st.insert(c) ;
        
        for(int i = 1 ; i <= n ; i ++){
            for(int j = i ; j > 0 ; j --){
                if(dp[j - 1] && st.count(s.substr(j - 1, i - j + 1))){
                    dp[i] = true ;
                    break ;
                }
            }
        }
        return dp[n] ;
    }
};