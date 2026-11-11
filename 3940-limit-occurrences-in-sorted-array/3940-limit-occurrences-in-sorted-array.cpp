class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int, int> f;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (f[nums[i]] < k) {
                ans.push_back(nums[i]);
                f[nums[i]]++;
            }
        }

        return ans;
    }
};