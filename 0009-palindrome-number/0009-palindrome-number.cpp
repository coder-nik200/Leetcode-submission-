class Solution {
public:
    bool isPalindrome(int x) {
        // Brute force
        // int temp = x;
        // long rev = 0;

        // while(x > 0) {
        //     int digit = x % 10;
        //     rev = (rev * 10) + digit;
        //     x /= 10;
        // }

        // if(rev == temp) {
        //     return true;
        // } else {
        //     return false;
        // }

        // Optimal approach
        string s = to_string(x);

        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};