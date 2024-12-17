#include <vector>
#include <iostream>

class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        auto first = nums.begin();
        auto last = nums.end();
        auto count = std::distance(first, last);

        while(count > 0) {
            auto it = first;
            auto step = count / 2;
            std::advance(it, step);

            if(*it < target) {
                first = ++it;
                count -= step + 1;
            }else
                count = step;
        }

        bool is_found = (!(first == last) && !(target < *first));

        if(is_found)
            return static_cast<int>(std::distance(nums.begin(), first));
        else
            return -1;
    }
};

int main() {
    std::cout << Solution{}.search({-1, 0, 3, 5, 9, 12}, 9) << "\n";
    std::cout << Solution{}.search({-1, 0, 3, 5, 9, 12}, 2) << "\n";
}