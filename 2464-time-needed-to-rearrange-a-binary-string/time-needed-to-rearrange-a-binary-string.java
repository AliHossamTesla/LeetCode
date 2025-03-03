class Solution {
    public int secondsToRemoveOccurrences(String s) {
        char[] a = s.toCharArray();
        int ans = 0 ;
        boolean ok = true ;
        while(ok){
            ok = false ;
            for(int i = 0 ; i < a.length - 1; i ++){
                if(a[i] == '0' && a[i + 1] == '1'){
                    char tmp = a[i] ;
                    a[i] = a[i + 1] ;
                    a[i + 1] = tmp ;
                    ok = true ;
                    i ++ ;
                }
            }
            if(ok) ans ++ ;
        }
        return ans ;
    }
}