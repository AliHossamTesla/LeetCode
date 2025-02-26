class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int mn = 0;
        int pref = 0;
        int mx = 0 ;
        for(int i : nums){
            pref += i;
            mn = Math.min(mn, pref);
            mx = Math.max(mx, pref);
        }
        return mx - mn ;
    }
}