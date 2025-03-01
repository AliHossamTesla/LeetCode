class Solution {
    public int[] applyOperations(int[] a) {
        int j = 0 ;
        int n = a.length ;
        for(int i = 0 ; i < n ; i ++){
            if(a[i] == 0) continue ;
            if(i < n - 1 && a[i] == a[i + 1]){
                a[i] *= 2 ;
                a[i + 1] = 0 ;
            }
            a[j ++] = a[i];
        }
        for(; j < n ; j ++) a[j] = 0 ;
        return a ;
    }
}