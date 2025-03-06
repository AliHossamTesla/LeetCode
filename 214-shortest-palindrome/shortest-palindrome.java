class Solution {
    public class Manacher {
        private String processedString;
        private int[] P; // Stores palindrome radii
        private int n; // Length of processed string

        Manacher(String s) {
            buildManacher(s);
        }

        // Preprocess: Add separators and sentinels
        private String preprocess(String s) {
            StringBuilder sb = new StringBuilder();
            sb.append('^'); // Sentinel to prevent bounds checking
            for (char c : s.toCharArray()) {
                sb.append('#').append(c);
            }
            sb.append("#$"); // Another sentinel
            return sb.toString();
        }

        // Manacher's algorithm to build palindrome radii array P
        public void buildManacher(String s) {
            processedString = preprocess(s);
            n = processedString.length();
            P = new int[n];
            int C = 0, R = 0; // Center and right boundary

            for (int i = 1; i < n - 1; i++) {
                int mirror = 2 * C - i;

                if (i < R) {
                    P[i] = Math.min(R - i, P[mirror]);
                }

                // Expand palindrome centered at i, with boundary checks
                while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 &&
                       processedString.charAt(i + P[i] + 1) == processedString.charAt(i - P[i] - 1)) {
                    P[i]++;
                }

                // Update center and right boundary
                if (i + P[i] > R) {
                    C = i;
                    R = i + P[i];
                }
            }
        }

        // Check if substring s[l:r] is a palindrome (0-based indexing)
        public boolean isPalindrome(int l, int r) {
            // Map original string indices to processed string indices
            int center = l + r + 2; // Add 1 for '^' and 1 for each '#'
            int len = r - l + 1;
            return P[center] >= len;
        }
    }

    public String shortestPalindrome(String s) {
        int n = s.length();
        Manacher mn = new Manacher(s);

        for (int i = n - 1; i >= 0; i--) {
            if (mn.isPalindrome(0, i)) {
                return new StringBuilder(s.substring(i + 1)).reverse().toString() + s;
            }
        }

        return new StringBuilder(s).reverse().toString() + s;
    }
}