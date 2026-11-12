class Solution {
public:
    int findMax(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }

        return maxi;
    }

    int possible(vector<int>& nums, int mid) {
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] + mid - 1) / mid;
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = findMax(nums);
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long minDivisor = possible(nums, mid);
            if (minDivisor <= threshold) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};