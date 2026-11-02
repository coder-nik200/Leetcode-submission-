class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++; // Increment and return if no carry
                return digits;
            }
            // Set current digit to 0 if it becomes 10
            digits[i] = 0;
        }

        // If we exit the loop, it means all digits were 9
        // Add 1 at the beginning
        digits.insert(digits.begin(), 1);
        return digits;
    }
};