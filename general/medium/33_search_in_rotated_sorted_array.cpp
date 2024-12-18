#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        auto pivot = std::partition_point(std::next(nums.begin()), nums.end(), [&nums](const auto& val) {
            return *nums.begin() < val;
        });

        if(auto [it, success] = m_binary_search(nums.begin(), pivot, target); success)
            return static_cast<int>(std::distance(nums.begin(), it));
        if(auto [it, success] = m_binary_search(pivot, nums.end(), target); success)
            return static_cast<int>(std::distance(nums.begin(), it));

        return -1;
    }
private:
    template <typename ForwardIt, typename T = typename std::iterator_traits<ForwardIt>::value_type>
    std::tuple<ForwardIt, bool> m_binary_search(ForwardIt first, ForwardIt last, const T& val) {
        auto it = std::lower_bound(first, last, val);
        bool is_found = (!(it == last) && !(val < *it));
        
        return {it, is_found};
    }
};

int main() {
    std::cout << Solution{}.search({4,5,6,7,0,1,2}, 0) << "\n";
    std::cout << Solution{}.search({4,5,6,7,0,1,2}, 3) << "\n";
    std::cout << Solution{}.search({1}, 0) << "\n";
}