class Solution {
    public long repairCars(int[] ranks, int cars) {
        long mn = Arrays.stream(ranks).max().getAsInt();
        long l = 0, r = cars * mn * cars ;
        while(l <= r){
            long md = l + (r - l)/2 ;
            int cnt = 0 ;
            for(int i : ranks){
                cnt += Math.sqrt(md/i);
            } 
            if(cnt >= cars)
                r = md - 1;
            else l = md + 1;
        }
        return l ;
    }
}