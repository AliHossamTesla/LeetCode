class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        while (l < r) {
            r = r & (r - 1); // Remove the least significant bit of r
        }
        return r;
    }
};
