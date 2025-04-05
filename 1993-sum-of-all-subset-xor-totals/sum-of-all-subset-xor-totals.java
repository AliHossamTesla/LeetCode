class Solution {
    public int subsetXORSum(int[] nums) {
        int Or = 0 ;
        for(int i : nums)
            Or |= i ;
        return (Or << (nums.length - 1));
    }
}