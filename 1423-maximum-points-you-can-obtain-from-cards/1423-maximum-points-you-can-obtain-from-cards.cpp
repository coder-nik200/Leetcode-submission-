class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int windowSize = n - k;
        int windowSum = 0;
        int totalSum = 0;
        int minSum = INT_MIN;

        for (int i = 0; i < n; i++) {
            totalSum += cardPoints[i];
        }

        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }

        minSum = windowSum;

        for (int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i];
            windowSum -= cardPoints[i - windowSize];
            minSum = min(minSum, windowSum);
        }

        return totalSum - minSum;
    }
};