#include <algorithm>
#include <cctype>
#include <iostream>
#include <array>

class Solution {
   public:
    std::string numberToWords(int num) {
        if (num == 0) return "Zero";
        std::string res{};
        size_t idx = 0;

        while (num > 0) {
            if (num % 1000 != 0) {
                std::string tmp{};
                helper(tmp, static_cast<size_t>(num) % 1000);
                tmp += thousands[idx];
                tmp += " ";
                res = std::move(tmp) + res;
            }

            ++idx;
            num /= 1000;
        }

        rtrim(res);
        return res;
    }

   private:
    void helper(std::string& s, size_t num) {
        if (num == 0)
            return;
        else if (num < 20) {
            s += less_than_twenty[num];
            s += " ";
            return;
        } else if (num < 100) {
            s += tens[num / 10];
            s += " ";
            helper(s, num % 10);
        } else {
            s += less_than_twenty[num / 100];
            s += " Hundred ";
            helper(s, num % 100);
        }
    }

    void rtrim(std::string& s) {
        auto last = std::find_if_not(s.rbegin(), s.rend(), [](const char& c) {
            return std::isspace(c);
        });
        s.erase(last.base(), s.end());
    }

   private:
    static constexpr std::array<const char*, 4> thousands{
        {"", "Thousand", "Million", "Billion"}};
    static constexpr std::array<const char*, 20> less_than_twenty{{
        "",        "One",     "Two",       "Three",    "Four",
        "Five",    "Six",     "Seven",     "Eight",    "Nine",
        "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen",
    }};
    static constexpr std::array<const char*, 10> tens = {{
        "",
        "",
        "Twenty",
        "Thirty",
        "Forty",
        "Fifty",
        "Sixty",
        "Seventy",
        "Eighty",
        "Ninety",
    }};
};

int main() {
    std::cout << Solution{}.numberToWords(123) << ".\n";
    std::cout << Solution{}.numberToWords(12345) << ".\n";
    std::cout << Solution{}.numberToWords(1234567) << ".\n";
    std::cout << Solution{}.numberToWords(1234567891) << ".\n";
}