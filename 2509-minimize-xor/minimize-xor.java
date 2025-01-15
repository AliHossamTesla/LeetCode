class Solution {
    public int minimizeXor(int num1, int num2) {
        int cnt = Integer.bitCount(num2) ;
        
        int ans = 0 ;
        for(int i = 30 ; i >= 0 && cnt != 0 ; i --){
            if((num1 >> i & 1) == 1){
                ans |= (1 << i) ;
                cnt -- ;
            }
        }
        for(int i = 0 ;i < 31 && cnt != 0; i ++){
            if((ans >> i & 1) == 0){
                ans |= (1 << i) ;
                cnt -- ;
            }
        }
        return ans ;
    }
}