class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        k -- ;
        int i = 0, cnt = 0;
        while(k){
            if(k & 1) cnt += operations[i] ;
            k >>= 1 ;
            i ++ ;
        }
        return char('a' + (cnt % 26)) ;
    }
};