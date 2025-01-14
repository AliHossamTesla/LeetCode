class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length ;
        int[] cntA = new int[n + 1];
        int[] cntB = new int[n + 1];

        int[] ans = new int[n];
        for(int i = 0 ; i < n ; i ++){
            if(A[i] == B[i]){
                ans[i] = (i != 0 ? ans[i - 1] : 0) + 1 ;
            }else{
                cntA[A[i]] ++ ;
                cntB[B[i]] ++ ;
                if(cntA[B[i]] != 0 && cntB[A[i]] != 0){
                    ans[i] = ans[i - 1] + 2 ;
                }else if(cntA[B[i]] != 0 || cntB[A[i]] != 0){
                    ans[i] = ans[i - 1] + 1 ;
                }else  ans[i] = (i != 0 ? ans[i - 1] : 0) ;
            }
        }
        return ans ;
    }
}