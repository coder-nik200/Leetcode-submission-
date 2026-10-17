class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Two Pointer
        int n = nums.size();
        int l = 0;
        int r = 0;

        while (l < n) {
            if (nums[l] != 0) {
                swap(nums[l], nums[r]);
                r++;
            }

            l++;
        }

        // int n = nums.size();
        // int j = -1; // Find first zero
        // for (int i = 0; i < n; i++) {
        //     if (nums[i] == 0) {
        //         j = i;
        //         break;
        //     }
        // }
        // // No zero found
        // if (j == -1)
        //     return;
        // // Move non-zero elements forward
        // for (int i = j + 1; i < n; i++) {
        //     if (nums[i] != 0) {
        //         swap(nums[i], nums[j]);
        //         j++;
        //     }
        // }
    }
};