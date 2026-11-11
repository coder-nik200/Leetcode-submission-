
class Solution {
public:
    // Checks whether we can make at least m bouquets by a given day
    bool possible(vector<int>& arr, int day, int m, int k) {
        int count = 0; // Counts consecutive bloomed flowers
        int noOfB = 0; // Counts total bouquets formed

        for (int i = 0; i < arr.size(); i++) {

            // If the flower has bloomed by the given day
            if (arr[i] <= day) {
                count++;
            } else {
                // Calculate bouquets from the previous consecutive flowers
                noOfB += count / k;

                // Reset count because the consecutive sequence is broken
                count = 0;
            }
        }

        // Count bouquets from the remaining consecutive flowers
        noOfB += count / k;

        // Check whether we have enough bouquets
        return noOfB >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        // Check whether enough flowers are available to make m bouquets
        long long val = 1LL * m * k;

        if (val > bloomDay.size())
            return -1;

        // Find the minimum and maximum bloom days
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i < bloomDay.size(); i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        // Set the binary search range
        int low = mini;
        int high = maxi;

        // Binary search to find the minimum required day
        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Check if we can make m bouquets by mid day
            if (possible(bloomDay, mid, m, k)) {

                // Possible, so try finding a smaller day
                high = mid - 1;
            } else {

                // Not possible, so we need more days
                low = mid + 1;
            }
        }

        // Low represents the minimum day required
        return low;
    }
};
