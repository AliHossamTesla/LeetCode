class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int cnt[1001] = {} ;
        for(int i : answers) cnt[i] ++ ;
        int ans = 0 ;
        for(int i = 0 ; i < 1001 ; i ++){
            ans += (cnt[i] + i)/(i + 1) * (i + 1);
        }
        return ans ;
    }
};