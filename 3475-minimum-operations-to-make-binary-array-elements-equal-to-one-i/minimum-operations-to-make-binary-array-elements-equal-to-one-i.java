class Solution {
    public int minOperations(int[] a) {
        int n = a.length ;
        int ans = 0 ;
        for(int i = 0 ; i < n - 2 ; i ++){
            if(a[i] == 0){
                a[i] = 1  ;
                a[i + 1] = 1 - a[i + 1] ;
                a[i + 2] = 1 - a[i + 2] ; 
                ans ++ ;
            }
        }
        return (a[n - 1] == 1 && a[n - 2] == 1 ? ans : -1);
    }
}