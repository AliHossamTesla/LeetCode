class Solution {
    public int minimumIndex(List<Integer> a) {
        int n = a.size();
        int[] r = new int[n];
        int[] l = new int[n];
        Arrays.fill(l, -1);
        Arrays.fill(r, -1);
        Map<Integer, Integer> cnt = new HashMap<>();
        for(int i = 0 ; i < n ; i ++){
            cnt.put(a.get(i), cnt.getOrDefault(a.get(i), 0) + 1);
            if(cnt.get(a.get(i)) > (i + 1)/2)
                l[i] = a.get(i);
            else if(i != 0 && l[i - 1] != -1 && cnt.get(l[i - 1]) > (i + 1)/2)
                l[i] = l[i - 1];
        }
        cnt = new HashMap<>();
        for(int i = n - 1; i >= 0 ; i --){
            cnt.put(a.get(i), cnt.getOrDefault(a.get(i), 0) + 1);
            int sz = (n - i);
            if(cnt.get(a.get(i)) > sz/2)
                r[i] = a.get(i);
            else if(i != n - 1 && r[i + 1] != -1 && cnt.get(r[i + 1]) > sz/2)
                r[i] = r[i + 1];
        }
        for(int i = 0 ; i < n - 1 ; i ++){
            if(l[i] != -1 && l[i] == r[i + 1]) return i;
        }
        return -1 ;
    }
}