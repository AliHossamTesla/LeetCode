import java.util.*;

class Solution {
    public int maximumSum(int[] nums) {
        // Map to store numbers grouped by their digit sums
        Map<Integer, List<Integer>> mp = new HashMap<>();

        // Group numbers by their digit sums
        for (int num : nums) {
            int sum = sumOfDigits(num);
            mp.computeIfAbsent(sum, k -> new ArrayList<>()).add(num);
        }

        int ans = -1;

        // Iterate through each group in the map
        for (List<Integer> group : mp.values()) {
            // Skip groups with fewer than 2 numbers
            if (group.size() < 2) continue;

            // Sort the group in descending order
            group.sort(Collections.reverseOrder());

            // Calculate the sum of the two largest numbers in the group
            int sum = group.get(0) + group.get(1);
            ans = Math.max(ans, sum);
        }

        return ans;
    }

    // Helper method to calculate the sum of digits of a number
    private int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}