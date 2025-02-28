class Solution {
    public int[] twoSum(int[] nums, int target) {
        List<int[]> a = new ArrayList<>();
        int n = nums.length ;
        for(int i = 0 ; i < n ; i ++){
            a.add(new int[]{nums[i], i});
        }
        a.sort((s, t) -> s[0] - t[0]);
        int l = 0, r = n - 1;
        while(l < r){
            int sum = a.get(l)[0] + a.get(r)[0];
            if(sum == target){
                return new int[]{a.get(l)[1], a.get(r)[1]};
            }else if(sum > target){
                r -- ;
            }else{
                l ++ ;
            }
        }
        return new int[]{-1, -1};
    }
}