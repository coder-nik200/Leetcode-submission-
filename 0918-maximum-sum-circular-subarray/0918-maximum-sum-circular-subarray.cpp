class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMaxSum = nums[0];
        int curMinSum = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];
        int totalSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            // Kadane's algorithm for maximum sum
            // Either extend previous subarray or start a new one
            curMaxSum = max(nums[i], curMaxSum + nums[i]);
            maxSum = max(maxSum, curMaxSum);

            // Kadane's algorithm for minimum sum
            // Either extend previous subarray or start a new one
            curMinSum = min(nums[i], curMinSum + nums[i]);
            minSum = min(minSum, curMinSum);

            // Calculate the total sum of all elements
            totalSum += nums[i];
        }

        // The circular sum is the total sum minus the minimum subarray sum
        int circularSum = totalSum - minSum;

        // Edge case: if all numbers are negative, then maxSum will be negative
        // and circularSum will be 0 (empty subarray), but we need to return the
        // max negative value
        if (circularSum == 0) {
            return maxSum;
        }

        // Return the maximum of the regular subarray sum and the circular
        // subarray sum
        return max(circularSum, maxSum);
    }
};