class Solution {
    public int majorityElement(int[] a) {
        int n = a.length;
        int b = -1 ;
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i ++){
            if(cnt == 0){
                b = a[i];
            }
            if(b == a[i]) cnt ++ ;
            else cnt -- ;
        }
        return b ;
    }
}