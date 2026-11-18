class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;
        long double base = x;

        if (power < 0) {
            base = 1.0L / base;
            power = -power;
        }

        double ans = 1.0L;
        while (power > 0) {
            if (power % 2 == 1) {
                ans *= base;
                power--;
            } else {
                base *= base;
                power /= 2;
            }
        }

        return (double)ans;
    }
};