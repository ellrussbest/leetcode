#include <cmath>
#include <iostream>
#include <limits>

class Solution {
   public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (float_eq_to(x, 1) || float_eq_to(x, 0)) return x;

        long y = n;

        if (n < 0) {
            x = 1 / x;
            y = std::abs(y);
        }

        double res = 1;
        while (y) {
            if (y % 2 == 1) res *= x;
            x *= x;
            y /= 2;
        }

        return res;
    }

   private:
    bool float_eq_to(double x, double y) {
        if (std::fabs(x - y) < std::numeric_limits<double>::epsilon())
            return true;
        return false;
    }
};

int main() {
    std::cout << Solution{}.myPow(2.00000, 10) << "\n";
    std::cout << Solution{}.myPow(2.10000, 3) << "\n";
    std::cout << Solution{}.myPow(2.00000, -2) << "\n";
}