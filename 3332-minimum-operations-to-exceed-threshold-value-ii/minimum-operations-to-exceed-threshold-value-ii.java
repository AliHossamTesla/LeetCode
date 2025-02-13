class Solution {
    public int minOperations(int[] nums, int k) {
        PriorityQueue<Long>q = new PriorityQueue<>();
        for(long i : nums) q.add(i);
        int cnt = 0 ;
        while(q.size() > 1){
            long a = q.poll();
            long b = q.poll();
            long mn = Math.min(a, b);
            long mx = Math.max(a, b);
            if(mn >= k) break ;
            cnt ++ ;
            q.add(2*mn + mx);
        }
        return cnt ;
    }
}