#include <iostream>
#include <vector>

class Solution {
   public:
    bool canPlaceFlowers(std::vector<int>&& flowerbed, int n) {
        if (n == 0) return true;

        for (auto it = flowerbed.begin(); it != flowerbed.end(); ++it) {
            auto left = std::make_reverse_iterator(it);
            auto right = std::next(it);

            if (*it == 0 && (left == flowerbed.rend() || *left == 0) &&
                (right == flowerbed.end() || *right == 0)) {
                *it = 1;
                --n;

                if (n == 0) break;
            }
        }

        return n == 0;
    }
};

int main() {
    std::cout << std::boolalpha;
    std::cout << Solution{}.canPlaceFlowers({1, 0, 0, 0, 1}, 1) << "\n";
    std::cout << Solution{}.canPlaceFlowers({1, 0, 0, 0, 1}, 2) << "\n";
    std::cout << Solution{}.canPlaceFlowers({0, 0, 1, 0, 0}, 1) << "\n";
}