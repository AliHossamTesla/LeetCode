class Solution {
    public long countBadPairs(int[] a) {
        long n = a.length;
        for(int i = 0 ; i < n ; i ++) a[i] -= i ;
        HashMap<Integer, Integer> cnt = new HashMap<>();
        for(int i : a) cnt.put(i, cnt.getOrDefault(i, 0) + 1);
        long ans = n * (n - 1)/2;
        for (long v : cnt.values()) {
            ans -= (v * (v - 1))/2;
        }
        return ans ;
    }
}