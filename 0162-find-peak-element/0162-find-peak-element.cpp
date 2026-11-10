class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // int st = 0;
        // int end = nums.size() - 1;

        // while (st < end) {
        //     int mid = st + (end - st) / 2;

        //     if (nums[mid] > nums[mid + 1]) {
        //         end = mid;
        //     } else {
        //         st = mid + 1;
        //     }
        // }

        // return st;

        // Simple Graph approch
        int n = nums.size();

        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int low = 1;
        int high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] > nums[mid - 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};