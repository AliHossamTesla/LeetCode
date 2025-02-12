class Solution{
    public int maximumSum(int[] nums) {
        Map<Integer, List<Integer>>mp = new HashMap<>();
        for(int i : nums){
            // mp.get().add(i);
            mp.computeIfAbsent(sumOfDigits(i), k -> new ArrayList<>()).add(i);
        }
        int ans = -1 ;
        for(List<Integer> cr : mp.values()){
            if(cr.size() <= 1) continue ;
            Collections.sort(cr);
            int res = cr.getLast();
            cr.removeLast();
            res += cr.getLast();
            ans = Math.max(ans, res);
        }
        return ans ;
    }
    private int sumOfDigits(int a){
        int cr = 0 ;
        while(a > 0){
            cr += a % 10 ;
            a /= 10 ;
        }
        return cr ;
    }
}