class Solution {
    public int maximumCount(int[] nums) {
        int cntP = 0, cntN = 0 ;
        for(int i : nums){
            cntP += (i > 0 ? 1 : 0);
            cntN += (i < 0 ? 1 : 0);
        }
        return (cntP > cntN ? cntP : cntN);
    }
}