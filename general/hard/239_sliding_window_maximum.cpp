#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>

class Solution {
public:
    std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
        std::vector<int> res;
        std::deque<size_t> dq;

        size_t left = 0;
        size_t right = 0;
        size_t window = static_cast<size_t>(k-1);

        for(; right < nums.size(); ++right) {
            if(!dq.empty() && left > dq.front())
                dq.pop_front();
            
            while(!dq.empty() && !(nums[right] < nums[dq.back()]))
                dq.pop_back();
            
            dq.emplace_back(right);

            if(right >= window) {
                res.emplace_back(nums[dq.front()]);
                ++left;
            }
        }

        return res;
    }

    std::vector<int> maxSlidingWindow_bruteforce(const std::vector<int>& nums, int k) {
        std::vector<int> res;

        for(auto i = nums.begin(); i != ++std::prev(nums.end(), k); ++i) {
            int max = *i;
            for(auto j = i; j != std::next(i, k); ++j) {
                max = std::max(max, *j);
            }
            res.emplace_back(max);
        }

        return res;
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
    std::cout << Solution{}.maxSlidingWindow({1,3,-1,-3,5,3,6,7}, 3) << "\n";
    std::cout << Solution{}.maxSlidingWindow({1}, 1) << "\n";

    std::cout << Solution{}.maxSlidingWindow_bruteforce({1,3,-1,-3,5,3,6,7}, 3) << "\n";
    std::cout << Solution{}.maxSlidingWindow_bruteforce({1}, 1) << "\n";
}