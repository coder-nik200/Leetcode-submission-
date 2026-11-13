class Solution {
public:
    int findMax(vector<int>& nums) {
        int maxi = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }

        return maxi;
    }

    int splitArray(vector<int>& nums, long long maxSum) {
        int subArrayCount = 1;
        long long countSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (countSum + nums[i] <= maxSum) {
                countSum += nums[i];
            } else {
                subArrayCount++;
                countSum = nums[i];
            }
        }

        return subArrayCount;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = findMax(nums);
        int high = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            int requiredSubarray = splitArray(nums, mid);
            if (requiredSubarray <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};