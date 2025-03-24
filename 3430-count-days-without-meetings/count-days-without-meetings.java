class Solution {
    public int countDays(int days, int[][] mt) {
        Arrays.sort(mt, (a, b) -> (a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]));
        List<int[]> intv = new ArrayList<>();
        int l = mt[0][0], r = mt[0][1] ;
        for (int i = 1; i < mt.length; i++) {
            if (mt[i][0] <= r) {
                r = Math.max(r, mt[i][1]); // Merge intervals
            } else {
                intv.add(new int[]{l, r});
                l = mt[i][0];
                r = mt[i][1];
            }
        }
        intv.add(new int[]{l, r});
        int prv = 1 ;
        int ans = 0 ;
        for(int[] v : intv){
            System.out.println(v[0] + " " + v[1]);
            ans += (v[0] - prv) ;
            prv = v[1] + 1;
        }
        return ans + (days - prv + 1);
    }
}