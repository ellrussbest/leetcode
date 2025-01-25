#include <vector>
#include <iostream>

class Solution {
public:
    bool lemonadeChange(const std::vector<int>& bills) {
        int fives = 0;
        int tens = 0;

        for(const auto& bill : bills) {
            if(bill == 5)
                ++fives;
            else if(bill == 10) {
                if(fives <= 0)
                    return false;
                ++tens, --fives;
            }else {
                if(tens > 0 && fives > 0)
                    --tens, --fives;
                else if(fives >= 3)
                    fives -= 3;
                else
                    return false;
            }
        }

        return true;
    }
};

int main() {
    std::cout << std::boolalpha;
    std::cout << Solution{}.lemonadeChange({5,5,5,10,20}) << "\n";
    std::cout << Solution{}.lemonadeChange({5,5,10,10,20}) << "\n";
    std::cout << Solution{}.lemonadeChange({5,5,5,20}) << "\n";
}