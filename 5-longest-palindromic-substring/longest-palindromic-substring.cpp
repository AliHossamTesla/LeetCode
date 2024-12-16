class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size() ;
        int mx = 0 ;
        string ans ;
        for(int i = 0 ; i < n ; i ++){
            int l = i - 1, r = i + 1;
            int cnt = 1 ;
            while(l >= 0 && r < n && s[l] == s[r]){
                cnt +=2 ;
                l -- ; r ++ ;
            }
            // dp[i][1] = cnt ;
            if(mx < cnt){
                ans = s.substr(l + 1, cnt) ;
                mx = cnt ;
            }
            l = i, r = i + 1 ;
            cnt = 0 ;
            while(l >= 0 && r < n && s[l] == s[r]){
                cnt += 2;
                l -- ; r ++ ;
            }
            // dp[i][0] = cnt ;
            if(cnt > mx){
                ans = s.substr(l + 1, cnt) ;
                mx = cnt ;
            }
        }
        return ans ;
    }
};