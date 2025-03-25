class Solution {
    public boolean checkValidCuts(int n, int[][] rectangles) {
        int m = rectangles.length ;
        int[][] mt = new int[m][2] ;
        int i = 0 ;
        for(int[] v : rectangles){
            mt[i ++] = new int[]{v[0], v[2]};
        }
        if(chk(mt)) return true ;
        i = 0 ;
        for(int[] v : rectangles){
            mt[i ++] = new int[]{v[1], v[3]};
        }
        if(chk(mt)) return true ;
        return false ;
    }
    private boolean chk(int[][] mt){
        Arrays.sort(mt, (a, b) -> (a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]));
        List<int[]> intv = new ArrayList<>();
        int l = mt[0][0], r = mt[0][1] ;
        for (int i = 1; i < mt.length; i++) {
            if (mt[i][0] < r) {
                r = Math.max(r, mt[i][1]); // Merge intervals
            } else {
                intv.add(new int[]{l, r});
                l = mt[i][0];
                r = mt[i][1];
            }
        }
        intv.add(new int[]{l, r});
        // for(int[] v : intv){
        //     System.out.println(v[0] + " " + v[1]);
        // }
        // System.out.println();
        if(intv.size() >= 3) return true ;
        else return false ;
    }
}