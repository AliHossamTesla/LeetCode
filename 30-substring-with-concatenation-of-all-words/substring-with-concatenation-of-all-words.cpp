class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& w) {
        vector<int>ans;
        int n = s.size(), m = w[0].size() , l = m * w.size() ;
        unordered_map<string, int>cnt ;
        for(auto c : w){
            cnt[c] ++ ;
        }
        
        for(int i = 0 ; i < m ; i ++){
            int l = i, r = i ;
            unordered_map<string, int>cr;
            int cnt_w = 0 ;
            while(r + m <= n){
                string tmp = s.substr(r, m) ;
                r += m ;
                cnt_w ++ ;
                if(cnt.count(tmp)){
                    cr[tmp] ++ ;
                    while(cr[tmp] > cnt[tmp]){
                        cr[s.substr(l, m)] -- ;
                        cnt_w -- ;
                        l += m ;
                    }
                }else{
                    cr.clear() ;
                    l = r ;
                    cnt_w = 0 ;
                }
                if(cnt_w == w.size()) ans.push_back(l) ;
            }
        }
        return ans ;
    }
};