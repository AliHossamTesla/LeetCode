import java.util.*;

class Solution {
    public int maximumSum(int[] nums) {
        int[] max = new int[100];

        int ans = -1;
        for (int num : nums) {
            int sum = sumOfDigits(num);
            if(max[sum] != 0) ans = Math.max(ans, max[sum] + num);
            max[sum] = Math.max(max[sum], num);
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