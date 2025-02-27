class Solution {
    public int lenLongestFibSubseq(int[] a) {
        int n = a.length;
        Map<Integer, Integer>[] dp = new HashMap[n];
        for(int i = 0 ; i < n ; i ++){
            dp[i] = new HashMap<>();
            for(int j = 0 ; j < i ; j ++){
                int target = a[i] - a[j];
                if (dp[j].containsKey(target)) {
                    int sequenceLength = dp[j].get(target) + 1;
                    dp[i].put(a[j], Math.max(dp[i].getOrDefault(a[j], 0), sequenceLength));
                }else{
                    dp[i].put(a[j], 2);
                }
            }
        }
        int maxLength = 0;
        for (Map<Integer, Integer> map : dp) {
            for (int length : map.values()) {
                maxLength = Math.max(maxLength, length);
            }
        }
        return (maxLength >= 3 ? maxLength : 0);
    }
}