class Solution {
public:
    int longestPalindrome(vector<string>& a) {
        int cnt[26][26] = {};
        for(auto s : a){
            cnt[s[0] - 'a'][s[1] - 'a'] ++ ;
        }
        int ans = 0 ;
        for(auto s : a)if(cnt[s[0] - 'a'][s[1] - 'a']){
            if(s[0] != s[1] && cnt[s[1] - 'a'][s[0] - 'a'] >= 1){
                ans += 2 ;
                cnt[s[0] - 'a'][s[1] - 'a'] -- ;
                cnt[s[1] - 'a'][s[0] - 'a'] -- ;
            }else if(s[0] == s[1] && cnt[s[1] - 'a'][s[0] - 'a'] >= 2){
                cnt[s[0] - 'a'][s[1] - 'a'] -= 2 ;
                ans += 2 ;
            }
        }
        for(int i = 0; i < 26 ; i ++) if(cnt[i][i]){
            ans ++ ;
            break ;
        }
        return ans * 2 ;
    }
};