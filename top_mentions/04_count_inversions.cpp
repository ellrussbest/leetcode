/**
 * Given an arary of integers, find the inversion Count in the array.
 *
 * Inversion Count: For an array, inversion count indicates how for (or
 * close) the array is from being sorted. If array is already sorted then the
 * inversion count is 0. If an array is sorted in the reverse order then the
 * inversion count is the maximum.
 *
 * Formally, two elements a[i] and a[j] from an inversion if a[i] > a[j] and i < j
 *
 * Input arr[] = [5, 2, 6, 3]
 * Output: 3
 *
 * Input arr[] = [3, 2, 1]
 * Output: 3
 *
 * Input arr[] = [1, 2, 3]
 * Output: 0
 */

#include <algorithm>
#include <iostream>
#include <vector>

template <typename BidirIt>
long int merge_sort(BidirIt first, BidirIt last) {
    auto dist = std::distance(first, last);

    if (dist <= 1) return 0;

    auto middle = std::next(first, dist / 2);
    auto left = merge_sort(first, middle);
    auto right = merge_sort(middle, last);

    auto it = std::prev(middle);
    it = std::lower_bound(middle, last, *it);
    auto len = std::distance(middle, it);

    std::inplace_merge(first, middle, last);
    return left + right + len;
}

auto count_inversions(std::vector<int>&& arr) {
    return merge_sort(arr.begin(), arr.end());
}

int main() {
    std::cout << count_inversions({5, 2, 6, 3}) << "\n";
    std::cout << count_inversions({3, 2, 1}) << "\n";
    std::cout << count_inversions({1, 2, 3}) << "\n";
    std::cout << count_inversions({1, 1, 2, 3}) << "\n";
    std::cout << count_inversions({5, 5, 5, 5}) << "\n";
}
