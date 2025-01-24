#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int findKthLargest(std::vector<int>&& nums, int k) {
        auto pos = std::prev(nums.end(), k);
        return quick_select(nums.begin(), nums.end(), pos);
    }
private:
    template <typename ForwardIt>
    int quick_select(ForwardIt first, ForwardIt last, ForwardIt pos) {
        while (first != last) { 
            auto pivot = *std::next(first, std::distance(first, last) / 2);
            auto middle1 = std::partition(first, last, [&](auto& el) {
                return el < pivot;
            });
            auto middle2 = std::partition(middle1, last, [=](auto& el) {
                return !(pivot < el);
            });
            
            if (pos < middle1) {
                last = middle1;
            } else if (pos >= middle2) {
                first = middle2;
            } else {
                return *pos;
            }
        }
        return *first; 
    }
};

int main() {
    std::cout << Solution{}.findKthLargest({3,2,1,5,6,4}, 2) << "\n";
    std::cout << Solution{}.findKthLargest({3,2,3,1,2,4,5,5,6}, 4) << "\n";
    std::cout << Solution{}.findKthLargest({2, 1}, 1) << "\n";
    std::cout << Solution{}.findKthLargest({99, 99}, 1) << "\n";
}