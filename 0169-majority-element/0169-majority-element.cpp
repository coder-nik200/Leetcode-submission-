class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = -1;

        // Find a candidate
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }

        // Validate the candidate
        int count1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == candidate) {
                count1++;
            }
        }

        // If count is greater than n / 2, return the
        // candidate; otherwise, return -1
        if (count1 > nums.size() / 2) {
            return candidate;
        } else {
            return -1;
        }
    }
};