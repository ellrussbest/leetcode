/**
 * Given an array `arr` containing both positive and negative integers,
 * the task is to compute the length of the largest subarray that has a sum of 0.
 * 
 * Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
 * Output: 5
 * Explanation: The largest subarray with a sum of 0 is [-2, 2, -8, 1, 7].
 * 
 * Input: arr[] = [2, 10, 4]
 * Output: 0
 * Explanation: There is no subarray with a sum of 0.
 * 
 * Input: arr[] = [1, 0, -4, 3, 1, 0]
 * Output: 5
 * Explanation: The subarray is [0, -4, 3, 1, 0].
 * 
 * Constraints:
 * 1 ≤ arr.size() ≤ 106
 * −103 ≤ arr[i] ≤ 103, for each valid i
 * 
 */


#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>

class Solution {
    public:
        int maxLen(const std::vector<int>& numbers) {
            std::unordered_map<int, int> presum;

            int sum = 0;
            int max_len = 0;

            for(size_t i = 0; i < numbers.size(); ++i) {
                sum += numbers[i];
                int idx = static_cast<int>(i);

                if(sum == 0)
                    max_len = idx + 1;
                
                if(auto it = presum.find(sum); it != presum.end())
                    max_len = std::max(max_len, idx - it->second);
                else
                    presum.emplace(sum, idx);
            }

            return max_len;
        }

        int maxLen_bruteforce(const std::vector<int>& numbers) {
            int max_len = 0;

            for(auto i = numbers.begin(); i != numbers.end(); ++i) {
                int sum = 0;
                for(auto j = i; j != numbers.end(); ++j) {
                    sum += *j;

                    if(sum == 0)
                        max_len = std::max(max_len, 
                                           static_cast<int>(std::distance(i, std::next(j))));
                }
            }

            return max_len;
        }
};

int main() {
    std::cout << Solution{}.maxLen({15, -2, 2, -8, 1, 7, 10, 23}) << "\n"; // 5
    std::cout << Solution{}.maxLen({2, 10, 4}) << "\n"; // 0
    std::cout << Solution{}.maxLen({1, 0, -4, 3, 1, 0}) << "\n"; // 5

    std::cout << Solution{}.maxLen_bruteforce({15, -2, 2, -8, 1, 7, 10, 23}) << "\n"; // 5
    std::cout << Solution{}.maxLen_bruteforce({2, 10, 4}) << "\n"; // 0
    std::cout << Solution{}.maxLen_bruteforce({1, 0, -4, 3, 1, 0}) << "\n"; // 5
}