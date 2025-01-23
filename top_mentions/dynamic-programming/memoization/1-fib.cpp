#include <iostream>
#include <unordered_map>

size_t fib_helper(int n, std::unordered_map<int, size_t>& memo) {
    if (n <= 2) 
        return 1;

    if (auto it = memo.find(n); it != memo.end()) 
        return it->second;

    auto res = fib_helper(n - 1, memo) + fib_helper(n - 2, memo);
    memo.emplace(n, std::move(res));
    return res;
}

size_t fibonacci(int n) {
    std::unordered_map<int, size_t> memo;
    return fib_helper(n, memo);
}

int main() {
    std::cout << fibonacci(6) << "\n";
    std::cout << fibonacci(7) << "\n";
    std::cout << fibonacci(8) << "\n";
    std::cout << fibonacci(50) << "\n";
}
