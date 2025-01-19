#include <vector>
#include <iostream>

class Solution {
public:
    int minDominoRotations(const std::vector<int>& tops, const std::vector<int>& bottoms) {
        int res = -1;

        for(int val = 1; val <= 6; ++val) {
            auto curr = helper(tops, bottoms, val);

            if(curr != -1 && (res == -1 || res > curr))
                res = curr;
        }

        return res;
    }
private:
    int helper(const std::vector<int>& tops, const std::vector<int>& bottoms, int val) {
        int res_top = 0;
        int res_bottom = 0;

        for(size_t i = 0; i < tops.size(); ++i) {
            if(tops[i] != val && bottoms[i] != val)
                return -1;
            else if(tops[i] != val)
                ++res_top;
            else if(bottoms[i] != val)
                ++res_bottom;
        }

        return std::min(res_top, res_bottom);
    }
};


int main() {
    std::cout << Solution{}.minDominoRotations({2,1,2,4,2,2}, {5,2,6,2,3,2}) << "\n";
    std::cout << Solution{}.minDominoRotations({3,5,1,2,3}, {3,6,3,3,4}) << "\n";
}