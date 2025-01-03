#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
    std::vector<int> sortColors(std::vector<int>&& nums) {
        quick_sort(nums.begin(), nums.end());
        return nums;
    }

private:
    template <typename ForwardIt>
    void quick_sort(ForwardIt first, ForwardIt last) {
        if(first == last)
            return;
        const auto pivot = *std::next(first, std::distance(first, last) / 2);

        auto middle1 = std::partition(first, last, [&pivot](auto& el){
            return el < pivot;
        });
        auto middle2 = std::partition(middle1, last, [&pivot](auto& el) {
            return !(pivot < el);
        });

        quick_sort(first, middle1);
        quick_sort(middle2, last);
    }
};

std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
    out << "{";
    for (char sep[]{0, ' ', 0}; const auto& el : v)
        out << sep << el, sep[0] = ',';
    out << "}";

    return out;
}

int main() {
    std::cout << Solution{}.sortColors({2,0,2,1,1,0}) << "\n";
    std::cout << Solution{}.sortColors({0,1,2}) << "\n";
}