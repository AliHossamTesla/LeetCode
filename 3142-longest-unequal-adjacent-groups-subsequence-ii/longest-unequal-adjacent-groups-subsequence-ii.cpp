class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& a, vector<int>& b) {
        int n = a.size() ;
        vector<int>dp(n, 1), par(n, -1);
        auto dist = [&](string s, string t){
            int cnt = 0 ;
            for(int i = 0 ; i < s.size() ; i ++){
                cnt += (s[i] != t[i]) ;
            }
            return cnt ;
        };
        int st = 0 ;
        for(int i = 0 ; i < n ; i ++){
            for(int j = i - 1; j >= 0 ; j --){
                if(b[i] != b[j] && a[i].size() == a[j].size() 
                && dist(a[i], a[j]) == 1 && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1 ;
                    par[i] = j ;
                    if(dp[i] > dp[st]){
                        st = i ;
                    }
                }
            }
        }
        vector<string> ans;
        while(st != -1){
            ans.push_back(a[st]) ;
            st = par[st] ;
        }
        reverse(begin(ans), end(ans)) ;
        return ans ;
    }
};