class Solution {
    public int edgeScore(int[] edges) {
        int n = edges.length ;
        long[] scores = new long[n] ;
        for(int i = 0 ; i < n ; i ++){
            scores[edges[i]] += i ;
        }
        int j = 0 ;
        for(int i = 1 ; i < n ; i ++){
            if(scores[i] > scores[j]){
                j = i ;
            }
        }
        return j ;
    }
}