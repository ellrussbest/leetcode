/**
* You are given a number as a string num, and an integer k. Build a new number result using digit of num such that no digit appears more than k times consecutively. You may use all digits or may not use all digits of num. Return the largest number possible.
*
* Example 1:
* Input: num = "3391933", k = 3
* Output: "9933313"
* Explanation: The largest possible number is "9933313", as you can see there are no continuous digits which is more than 3 times and largest number.
* 
* Example 2:
* Input: num = "1121212", k = 2
* Output: "221211"
* Explanation: The largest possible number is "221211", as you can see there is no continuous digit which is more than 2 times
*
*/

#include <map>
#include <iostream>


std::string maximum_number(const std::string& number, const int& k) {
    std::map<char, int, std::greater<char>> m_map;
    std::string res;
    int count = 0;

    for(const auto& digit : number) {
        auto [it, success] = m_map.try_emplace(digit, 1);

        if(!success)
            ++it->second;
    }

    while(!m_map.empty()) {
        auto it = m_map.begin();
        
        if(count == k) {
            ++it;
            count = 0;
        }else
            ++count;

        if(it == m_map.end())
            break;
        
        res += it->first;
        --it->second;

        if(it->second == 0) {
            m_map.erase(it);
            count = 0;
        }
    }

    return res;
}

int main() {
    std::cout << maximum_number("3391933", 3) << "\n";
    std::cout << maximum_number("1121212", 2) << "\n";
}