#include <iostream>
#include <vector>
#include <stack>
#include <limits>

class Solution {
public:
    bool find132pattern(const std::vector<int>& nums) {
        std::stack<int> st;
        auto k = std::numeric_limits<int>::lowest();

        for(auto i = nums.rbegin(); i != nums.rend(); ++i) {
            if(*i < k)
                return true;
            
            while(!st.empty() && st.top() < *i) {
                k = st.top();
                st.pop();
            }

            st.emplace(*i);
        }

        return false;
    }

    bool find132pattern_bruteforce(const std::vector<int>& nums) {
        for(size_t i = 0; i < nums.size(); ++i) {
            for(size_t j = i + 1; j < nums.size(); ++j) {
                for(size_t k = j + 1; k < nums.size(); ++k) {
                    if(nums[i] < nums[k] && nums[k] < nums[j])
                        return true;
                }
            }
        }
        return false;
    }
};

int main() {
    std::cout << std::boolalpha;
    std::cout << Solution{}.find132pattern_bruteforce({1,2,3,4}) << "\n";
    std::cout << Solution{}.find132pattern_bruteforce({3,1,4,2}) << "\n";
    std::cout << Solution{}.find132pattern_bruteforce({-1,3,2,0}) << "\n";
    std::cout << Solution{}.find132pattern_bruteforce({3,5,0,3,4}) << "\n";

    std::cout << "\n";
    std::cout << Solution{}.find132pattern({1,2,3,4}) << "\n";
    std::cout << Solution{}.find132pattern({3,1,4,2}) << "\n";
    std::cout << Solution{}.find132pattern({-1,3,2,0}) << "\n";
    std::cout << Solution{}.find132pattern({3,5,0,3,4}) << "\n";
}