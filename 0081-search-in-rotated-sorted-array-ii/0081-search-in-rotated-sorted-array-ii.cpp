class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // Linear Search: TC - O(n)
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] == target) {
        //         return true;
        //     }
        // }

        // return false;

        // Binary Search: TC - O(log n)
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Handle duplicates
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            } else if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};