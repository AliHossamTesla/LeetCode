class Solution {
    public int tupleSameProduct(int[] a) {
        int ans = 0 ;
        int n = a.length;
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i = 0 ; i < n ; i ++){
            for(int j = i + 1; j < n ; j ++){
                int product = a[i] * a[j];
                mp.put(product, mp.getOrDefault(product, 0) + 1);
            }
        }
        for(int cnt : mp.values()){
            if(cnt >= 2){
                ans += cnt * (cnt - 1) * 4 ;
            }
        }
        return ans ;
    }
}