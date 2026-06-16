class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;

        long long N = n;

        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }

        while (N > 0) {
            ans *= x;
            N--;
        }

        return ans;
    }
};