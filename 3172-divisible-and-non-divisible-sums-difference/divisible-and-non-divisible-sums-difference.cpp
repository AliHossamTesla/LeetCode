class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = 0 ;
        for(int i= 1; i <= n ; i ++){
            sum += (i % m ? i : -i) ;
        }
        return sum ;
    }
};