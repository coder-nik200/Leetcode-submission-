class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWater = 0;
        int i = 0;
        int j = n - 1;

        while (i < j) {
            int width = j - i;
            int h = min(height[i], height[j]);
            int currwater = width * h;
            maxWater = max(maxWater, currwater);

            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxWater;
    }
};