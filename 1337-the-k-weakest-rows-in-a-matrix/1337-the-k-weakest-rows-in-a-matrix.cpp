class Solution {
public:
    int lowerBound(vector<int>& mat, int n) {
        int low = 0;
        int high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mat[mid] >= 1) {
                low = mid + 1;
            } else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            int soldiers = lowerBound(mat[i], m);

            v.push_back({soldiers, i});
        }

        sort(v.begin(), v.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};