class Solution {
    public int xorAllNums(int[] a, int[] b) {
        int xr = 0 ;
        if(b.length % 2 == 1){
            for(int i : a)
                xr ^= i ;
        }
        if(a.length % 2 == 1){
            for(int i : b)
                xr ^= i ;
        }
        return xr ;
    }
}