class Solution {
    public void rotate(int[] a, int k) {
        int n = a.length;
        k %= n ;
        int[] tmp = new int[k];
        for(int i = 1 ; i <= k ; i ++)
            tmp[k - i] = a[n - i];
        for(int i = n - k - 1 ;i >= 0 ; i --){
            a[i + k] = a[i]; 
        }
        for(int i = 0 ; i < k ; i ++){
            a[i] = tmp[i];
        }
    }
}