#include <iostream>
#include <vector>

class Solution {
public:
    int majorityElement(const std::vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for(auto i = nums.begin(); i != nums.end(); ++i) {
            if(count == 0)
                candidate = *i;
                
            if(*i == candidate)
                ++count;
            else
                --count;
        }

        return candidate;
    }
};

int main() {
    std::cout << Solution{}.majorityElement({3,2,3}) << "\n";
    std::cout << Solution{}.majorityElement({2,2,1,1,1,2,2}) << "\n";
    std::cout << Solution{}.majorityElement({3,3,4}) << "\n";
}