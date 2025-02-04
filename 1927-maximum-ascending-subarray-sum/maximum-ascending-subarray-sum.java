class Solution {
    public int maxAscendingSum(int[] a) {
        int ans = a[0];
        int cr = ans ;
        for(int i = 1 ;i < a.length ; i ++){
            if(a[i] > a[i - 1]){
                cr += a[i];
            }else{
                cr = a[i];
            }
            ans = Math.max(ans, cr);
        }
        return ans ;
    }
}