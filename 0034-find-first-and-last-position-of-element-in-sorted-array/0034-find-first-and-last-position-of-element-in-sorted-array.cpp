class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (target > nums[mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return st;
    }

    int upperBound(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (target >= nums[mid]) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return st;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lowerBound(nums, target);
        int last = upperBound(nums, target) - 1;

        if (first == nums.size() || nums[first] != target) {
            return {-1, -1};
        }

        return {first, last};
    }
};