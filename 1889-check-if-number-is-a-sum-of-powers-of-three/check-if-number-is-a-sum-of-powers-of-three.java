class Solution {
    public boolean checkPowersOfThree(int n) {
        int cr = 3 ;
        for(int i = 0 ; i < 18 ; i ++) cr *= 3 ;
        while(n > 0){
            if(n/cr > 1){
                return false ;
            }
            n -= (n/cr) * cr ;
            cr /= 3 ;
        }
        return true ;
    }
}