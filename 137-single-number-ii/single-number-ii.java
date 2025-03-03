class Solution {
    public int singleNumber(int[] a) {
        int ones = 0, twos = 0 ;
        for(int i : a){
            ones ^= (i & ~twos);
            twos ^= (i & ~ones);
        }
        return ones ;
    }
}