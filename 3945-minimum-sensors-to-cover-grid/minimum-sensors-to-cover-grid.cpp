class Solution {
public:
    int minSensors(int n, int m, int k) {
        int len = 2*k + 1 ;
        return ((n + len - 1)/len) * ((m + len - 1)/len) ;
    }
};