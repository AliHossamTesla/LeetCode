class Solution {
    public int removeDuplicates(int[] a) {
        int j = 2 ;
        for(int i = 2 ; i < a.length ; i ++){
            if(a[i] != a[j - 1] || a[i] != a[j - 2]){
                a[j++] = a[i];
            }
        }
        return j ;
    }
}