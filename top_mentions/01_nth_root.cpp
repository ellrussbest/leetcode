/**
 * Implement a function root that calculates the nth root of a number. The
 * function takes a nonnegative number x and a positive integer n. and returns
 * the positive nth root of x within an error of 1e-9 i.e (suppose the real
 * root is y, then the error is: |y-root(x,n) and must satify |y-root(x,n)| <
 * 1e-9).
 */

#include <cmath>
#include <iostream>
#include <limits>

class Solution {
   public:
    double nth_root(double x, int n) {
        double left = 1;
        double right = x;

        while ((right - left) > m_epsilon) {
            double mid = (left + right) / 2;

            if (std::pow(mid, n) > x)
                right = mid;
            else
                left = mid;
        }

        return left;  // either left or right can be returned because they are
                      // both within the margin or error
    }

   private:
    const double m_epsilon = 1e-9;
};

int main() {
    std::cout << Solution{}.nth_root(27, 3) << "\n";
    std::cout << Solution{}.nth_root(8, 3) << "\n";
    std::cout << Solution{}.nth_root(625, 2) << "\n";
    std::cout << Solution{}.nth_root(10.985463567, 3) << "\n";  // 2.223
}