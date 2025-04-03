class Solution {
    public long maximumTripletValue(int[] a) {
        long dif = 0;
        long prod = 0 ;
        long prf = 0 ;
        for(int i : a){
            prod = Math.max(prod, dif * i);
            dif = Math.max(dif, prf - i);
            prf = Math.max(prf, i);
        }
        return Math.max(0, prod) ;
    }
}