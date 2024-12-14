class Solution {
public:
    int numDigits(int n) {
        if (n == 0) return 1; // Special case for 0
        return floor(log10(n) + 1);
    }
    bool isPalindrome(int x) {
        if(x < 0) return false ;
        int n = numDigits(x) ;
        for(int i = 0 ; i < n/2 ; i ++){
            if(int(x / pow(10, i)) % 10 != int(x / pow(10, n - i - 1)) % 10)
                return false ;
        }
        return true ;
    }
};