class Solution {
public:
    int divide(int dividend, int divisor) {
        // Overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine the sign of the answer
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Use long long to safely handle INT_MIN
        long long a = dividend;
        long long b = divisor;

        // Work with positive values
        if (a < 0) a = -a;
        if (b < 0) b = -b;

        long long quotient = 0;

        // Find the quotient using powers of 2
        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            // Double the divisor until it becomes too large
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            quotient += multiple;
        }

        // Apply the sign
        if (negative)
            quotient = -quotient;

        // Clamp to 32-bit signed integer range
        if (quotient > INT_MAX)
            return INT_MAX;

        if (quotient < INT_MIN)
            return INT_MIN;

        return (int)quotient;
    }
};