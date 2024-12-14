class Solution {
public:
    double myPow(double x, long long n) {
        if(n == 0) return 1 ;
        if(n == 1) return x ;
        if(n < 0){
            double ans ;
            n *= -1 ;
            if(n & 1) ans = x  * myPow(x, n - 1) ;
            else ans = myPow(x * x, n/2) ;
            return 1/ans ;
        }else{
            if(n & 1) return x  * myPow(x, n - 1) ;
            else return myPow(x * x, n/2) ;
        }
    }
};