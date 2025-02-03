class Solution {
    public boolean check(int[] a) {
        int n = a.length;
        for(int i = 0 ; i < n ; i ++){
            boolean ok = true ;
            for(int j = 1 ; j < n ; j ++){
                if(a[(i + j) % n] < a[(i + j - 1 + n) % n]){
                    ok = false ;
                    break ;
                }
            }
            if(ok){
                return true ;
            }
        }
        return false ;
    }
}