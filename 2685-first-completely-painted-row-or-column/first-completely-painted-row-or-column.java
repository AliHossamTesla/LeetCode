class Solution {
    public int firstCompleteIndex(int[] a, int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int[] C = new int[m];
        int[] R = new int[n];
        int[] idxR = new int[n * m + 1] ;
        int[] idxC = new int[n * m + 1] ;
        for(int i = 0 ; i < n ; i ++){
            for(int j = 0 ; j < m ; j ++){
                idxR[mat[i][j]] = i ;
                idxC[mat[i][j]] = j ;
            }
        }  
        for(int i = 0 ; i < n * m ; i ++){
            R[idxR[a[i]]] ++ ;
            C[idxC[a[i]]] ++ ;
            if(R[idxR[a[i]]] == m || C[idxC[a[i]]] == n){
                return i ;
            }
        }
        return -1 ;
    }
}