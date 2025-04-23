class Solution {
public:
    int countLargestGroup(int n) {
        map<int, int>mp1, mp2 ;
        for(int i = 1 ; i <= n ; i ++){
            int sum = 0, tmp = i;
            while(tmp){
                sum += tmp % 10 ;
                tmp /= 10 ;
            }
            mp1[sum] ++ ;
        }
        for(auto [k, v] : mp1) mp2[v] ++ ;
        return mp2.rbegin()->second ;
    }
};