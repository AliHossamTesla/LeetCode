class Solution {
    public int singleNumber(int[] a) {
        int n = a.length;
        Arrays.sort(a);
        for(int i = 1; i < n ; i += 3){
            if(a[i] != a[i - 1]){
                return a[i - 1];
            }
        }
        return a[n - 1];
    }
}