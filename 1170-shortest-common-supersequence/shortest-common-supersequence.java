import java.util.Arrays;

class Solution {
    public String shortestCommonSupersequence(String s, String t) {
        int n = s.length();
        int m = t.length();
        int[][] dp = new int[n + 1][m + 1];
        
        // Initialize the dp table
        for (int i = 0; i <= n; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }
        
        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                }
            }
        }
        
        // Reconstruct the shortest common supersequence
        StringBuilder ans = new StringBuilder();
        int i = n, j = m;
        while (i > 0 || j > 0) {
            if (i > 0 && j > 0 && s.charAt(i - 1) == t.charAt(j - 1)) {
                ans.append(s.charAt(i - 1));
                i--;
                j--;
            } else if (i > 0 && dp[i][j] == dp[i - 1][j] + 1) {
                ans.append(s.charAt(i - 1));
                i--;
            } else if (j > 0 && dp[i][j] == dp[i][j - 1] + 1) {
                ans.append(t.charAt(j - 1));
                j--;
            }
        }
        
        return ans.reverse().toString();
    }
}