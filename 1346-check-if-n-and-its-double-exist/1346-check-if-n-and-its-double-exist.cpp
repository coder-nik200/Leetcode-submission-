class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // Brute force: TC - O(n^2)
        /*
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && arr[i] == 2 * arr[j]) {
                    return true;
                }
            }
        }

        return false;
        */

        // Binary Search: TC - O(n log n)

        int n = arr.size();

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            int target = arr[i] * 2;

            int low = 0;
            int high = n - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (arr[mid] == target) {
                    if (mid != i) {
                        return true;
                    }

                    break;
                } else if (arr[mid] < target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};