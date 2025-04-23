class Solution {
public:
    int countLargestGroup(int n) {
        int cnt[40] = {}, cnt1[1000] ;
        for(int i = 1 ; i <= n ; i ++){
            int sum = 0, tmp = i;
            while(tmp){
                sum += tmp % 10 ;
                tmp /= 10 ;
            }
            cnt[sum] ++ ;
        }
        for(int i = 0 ; i < 40 ; i ++)
            if(cnt[i]) cnt1[cnt[i]] ++ ;
        for(int i = 999 ; i >= 0 ; i --)
            if(cnt1[i] != 0) return cnt1[i] ; 
        return -1 ;
    }
};