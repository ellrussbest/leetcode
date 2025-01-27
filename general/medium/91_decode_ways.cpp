#include <iostream>
#include <unordered_map>
#include <string>

class Solution {
   public:
    int numDecodings(std::string s) {
        std::unordered_map<std::string, int> memo;
        return helper(s, memo); 
    }

   private:
    int helper(std::string s, auto& memo) {
        if(s.size() == 0)
            return 1;
        if(s[0] == '0')
            return 0;

        if(auto it = memo.find(s); it != memo.end())
            return it->second;

        int count = 0;

        if(s.size() >= 1)
            count += helper(s.substr(1), memo);
        
        if(s.size() >= 2
            && std::stoi(s.substr(0, 2)) >= 10
            && std::stoi(s.substr(0, 2)) <= 26)
            count += helper(s.substr(2), memo);

        memo.try_emplace(s, count);
        return count;
    }
};

int main() {
    std::cout << Solution{}.numDecodings("12") << "\n";
    std::cout << Solution{}.numDecodings("226") << "\n";
    std::cout << Solution{}.numDecodings("06") << "\n";
    std::cout << Solution{}.numDecodings("121") << "\n";
    std::cout << Solution{}.numDecodings("1234") << "\n";
    std::cout << Solution{}.numDecodings("122016") << "\n";
}