class Solution {
    public int myAtoi(String s) {
        if(s.length() == 0) return 0 ;
        char[] a = s.toCharArray();
        if(a[0] == ' ' || a[0] == '0' || a[0] == '-' || (a[0] >= '1' && a[0] <= '9') || a[0] == '+'){
            int j = 0 ;
            while(j < a.length && a[j] == ' ') j ++ ;
            if(j == a.length) return 0 ;
            boolean sgn = false ;
            if(a[j] == '-'){
                sgn = true ;
                j ++ ;
            }else if(a[j] == '+') j ++ ;
            while(j < a.length && a[j] == '0') j ++ ;
            if(j == a.length) return 0 ;
            StringBuilder ans = new StringBuilder();
            while(j < a.length && a[j] >= '0' && a[j] <= '9') ans.append(a[j ++]);
            if(ans.length() > 10){
                if(sgn) return Integer.MIN_VALUE;
                else return Integer.MAX_VALUE;
            }
            if(ans.length() == 0) return 0 ;
            long cur = Long.parseLong(ans.toString());
            if(sgn){
                cur *= -1 ;
                return (int)Math.max(cur, Integer.MIN_VALUE);
            }else{
                return (int)Math.min(cur, Integer.MAX_VALUE);
            }
        }else return 0 ;
    }
}