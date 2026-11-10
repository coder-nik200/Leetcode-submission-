class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
            if (nums[low] < nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }

            if (nums[low] == nums[high]) {
                ans = min(ans, nums[low]);
                low++;
                high--;
                continue;
            }

            int mid = low + (high - low) / 2;

            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            } else if (nums[mid] <= nums[high]) {
                ans = min(ans, nums[mid]);
                high = high - 1;
            } else {
                low++;
            }
        }

        return ans;
    }
};