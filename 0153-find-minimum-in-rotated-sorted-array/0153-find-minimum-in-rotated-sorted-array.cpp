class Solution {
public:
    int findMin(vector<int>& nums) {
        // Brute force TC = O(n) SC = O(1)
        // int min = nums[0];

        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] < min) {
        //         min = nums[i];
        //     }
        // }

        // return min;

        // Optimal approach    TC = O(log n)   SC = O(1)
        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            if (nums[mid] < nums[end]) {
                end = mid;
            } else {
                st = mid + 1;
            }
        }

        return nums[end];
    }
};