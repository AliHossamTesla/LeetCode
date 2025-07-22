class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
        int cnt[10005] = {} ;
        int sum = 0, ans = 0;
        for(int i = 0, j = 0 ; i < a.size() ; i ++){
            cnt[a[i]] ++ ;
            sum += a[i]  ;
            if(cnt[a[i]] > 1){
                while(cnt[a[i]] > 1){
                    cnt[a[j]] -- ;
                    sum -= a[j] ;
                    j ++ ;
                }
            }
            ans = max(ans, sum) ;
        }
        return ans ;
    }
};