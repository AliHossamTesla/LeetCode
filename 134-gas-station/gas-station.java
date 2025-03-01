class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length ;
        int sm = 0 ;
        int l = 0 ;
        for(int r = 0 ; r < 2*n ; r ++){
            sm += gas[r % n] - cost[r % n];
            while(sm < 0){
                sm = sm - gas[l % n] + cost[l % n];
                l ++ ; 
            }
            if(r - l + 1 == n){
                return l ;
            }
            // System.out.println("["+ l + " : " + r + "] = " + sm);
        }
        return -1 ;
    }
}