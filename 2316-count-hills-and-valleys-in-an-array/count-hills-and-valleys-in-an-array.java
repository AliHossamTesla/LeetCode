class Solution {
    public int countHillValley(int[] a) {
        int ans = 0 ;
        int i = 0 ;
        while(i < a.length && a[i] == a[0]) i ++ ;
        for(; i < a.length - 1 ;){
            int j = i ;
            while(j < a.length && a[j] == a[i]){
                j ++ ;
            }
            if(j >= a.length) break ;
            if(!((a[i] > a[i - 1]) ^ (a[i] > a[j]))){
                ans ++ ;
            }
            i = j ;
        }
        return ans ;
    }
}