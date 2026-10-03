class Solution {
public:
    int fib(int n) {
        // Brute force
        // if(n <= 1) {
        //     return n;
        // }

        // return fib(n - 1) + fib(n - 2);

        // Optimal approach
        if (n <= 1) {
            return n;
        }

        int a = 0;
        int b = 1;

        for (int i = 2; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};