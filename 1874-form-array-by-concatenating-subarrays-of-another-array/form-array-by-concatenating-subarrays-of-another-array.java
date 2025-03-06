class Solution {
    public boolean canChoose(int[][] g, int[] nums) {
        List<Integer>[] pi = new List[g.length];
        int idx = 0 ;
        for(int[] cr : g){
            pi[idx] = new ArrayList<>();
            pi[idx].add(0);
            for(int i = 1 ; i < cr.length ; i ++){
                int j = pi[idx].getLast();
                while(j > 0 && cr[i] != cr[j]) j = pi[idx].get(j - 1);
                if(cr[i] == cr[j]) j ++ ;
                pi[idx].add(j);
            }
            idx ++ ;
        }
        idx = 0 ;
        for(int i = 0 ; i < g.length ; i ++){
            // System.out.println(idx);
            int prv = pi[i].getLast();
            boolean ok = false ;
            for(; idx < nums.length ; idx ++){
                int j = prv ;
                while(j != 0 && nums[idx] != g[i][j]) j = pi[i].get(j - 1);
                if(nums[idx] == g[i][j]) j ++ ;
                if(j == g[i].length){
                    idx ++ ;
                    ok = true ;
                    break ;
                }
                prv = j ;
            }
            if(!ok) return false ;
        }
        return true ;
    }
}