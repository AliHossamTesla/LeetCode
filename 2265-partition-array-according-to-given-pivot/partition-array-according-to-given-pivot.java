class Solution {
    public int[] pivotArray(int[] nums, int pivot) {
       List<Integer>[] lst = new List[3];
        for(int i = 0 ; i < 3 ; i ++) lst[i] = new ArrayList<>();
        for(int i : nums){
            lst[(i < pivot? 0 : (i == pivot ? 1 : 2))].add(i);
        }
        int j = 0 ;
        for(int i = 0 ; i < 3 ; i ++){  
            for(int el : lst[i]){
                nums[j++] = el ;
            }
        }
        return nums;
    }
}