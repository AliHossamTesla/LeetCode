class Solution {
public:
    bool isPowerOfThree(int n) {
        if(!n) return 0 ;
        while(n % 3 == 0) n /= 3 ;
        return n == 1 ;
    }
};