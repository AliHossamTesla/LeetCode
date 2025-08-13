class Solution {
public:
    bool isPowerOfThree(int n) {
        long long cr = 1 ;
        while(cr < n) cr *= 3 ;
        return cr == n ;
    }
};