#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
    std::vector<int> sortArray(std::vector<int>&& nums) {
        merge_sort(nums.begin(), nums.end());
        return nums;
    }

private:
    template <typename BidirIt>
    void merge_sort(BidirIt first, BidirIt last) {
        auto dist = std::distance(first, last);
        if(dist <= 1)
            return;
        
        auto middle = std::next(first, dist / 2);
        merge_sort(first, middle);
        merge_sort(middle, last);
        std::inplace_merge(first, middle, last);
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
    std::cout << Solution{}.sortArray({5,2,3,1}) << "\n";
    std::cout << Solution{}.sortArray({5,1,1,2,0,0}) << "\n";
}