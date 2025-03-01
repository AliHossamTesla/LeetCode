class Solution {
    public int candy(int[] a) {
        int n = a.length ;
        int ans = n ;
        int i = 1 ;
        while(i < n){
            while(i < n && a[i] == a[i - 1]){
                i ++ ;
                continue ;
            }
            int peek = 0 ;
            while(i < n && a[i] > a[i - 1]){
                peek ++ ;
                ans += peek;
                i ++ ;
            }
            int valley = 0 ;
            while(i < n && a[i] < a[i - 1]){
                valley ++ ;
                ans += valley ;
                i ++ ;
            }
            ans -= Math.min(valley, peek);
        }
        return ans ;
    }
}