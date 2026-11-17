class Solution {
public:
    bool isPerfectSquare(int num) {
        // Linear Search: TC - O(sqrt{n})
        /*
        for (long long i = 1; i * i <= num; i++) {
            if (i * i == num) {
                return true;
            }
        }

        return false;
        */

        // Binary Search: TC - O(log n)
        long long low = 1;
        long long high = num;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            long long square = mid * mid;

            if (square == num) {
                return true;
            } else if (square < num) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};