class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& a, vector<int>& b) {
        int opt1 = 0, opt2 = 1 ;
        vector<string>ans1, ans2;
        for(int i = 0 ; i < a.size() ; i ++){
            if(opt1 == b[i]){
                opt1 = 1 - opt1 ;
                ans1.push_back(a[i]) ;
            }
            if(opt2 == b[i]){
                opt2 = 1 - opt2 ;
                ans2.push_back(a[i]) ;
            }
        }
        return (ans1.size() > ans2.size() ? ans1 : ans2) ;
    }
};