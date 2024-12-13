class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int>cnt ;
        int l = 0, ans = INT_MIN ;
        for(int r = 0 ; r < s.size() ; r ++){
            cnt[s[r]] ++ ;
            while(cnt[s[r]] > 1) cnt[s[l ++]] -- ;
            ans = max(ans, r - l + 1) ;    
        }
        return ans > INT_MIN ? ans : 0 ;
    }
};