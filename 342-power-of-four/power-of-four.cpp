class Solution {
public:
    bool isPowerOfFour(int n) {
        return __builtin_popcount(n) == 1 && (__lg(n) & 1 ^ 1) ;
    }
};