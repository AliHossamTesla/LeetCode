class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int n = nums1.length;
        int m = nums2.length;
        int i1 = 0 ;
        int i2 = 0 ;
        List<int[]> ans = new ArrayList<>();
        while(i1 < n && i2 < m){
            if(nums1[i1][0] == nums2[i2][0]){
                ans.add(new int[]{nums1[i1][0], nums1[i1][1] + nums2[i2][1]});
                i1 ++ ;
                i2 ++ ;
            }else if(nums1[i1][0] < nums2[i2][0]) ans.add(nums1[i1++]);
            else ans.add(nums2[i2++]);
        }
        while(i1 < n)
            ans.add(nums1[i1++]);
        while(i2 < m)
            ans.add(nums2[i2++]);
        int[][] ret = new int[ans.size()][2];
        for(int i = 0 ; i < ans.size() ; i ++){
            ret[i] = ans.get(i);
        }
        return ret ;
    }
}