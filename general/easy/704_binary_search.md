# Binary Search Solution: Intuition

This solution performs a binary search on a sorted vector `nums` to find the position of a `target` value. If the target exists, the index of the target in the vector is returned. If not, `-1` is returned.

## Step-by-Step Explanation:

1. **Initialization**:
   - We define two iterators: `first` and `last`, which represent the range of indices in the vector `nums` to be searched. We also calculate the total number of elements, `count`, by taking the distance between `first` and `last`.

   ```cpp
   auto first = nums.begin();
   auto last = nums.end();
   auto count = std::distance(first, last);
   ```

2. **Binary Search Loop**:
   - We perform the binary search in a `while` loop, which continues as long as there are elements to search (`count > 0`).
   - In each iteration:
     - We calculate the middle point (`step`), and move the `first` iterator to the middle using `std::advance`.
     - If the element at the middle point is less than the target, we move the `first` iterator to the right of the middle point and reduce the search range (`count -= step + 1`).
     - If the element at the middle point is greater than or equal to the target, we shrink the search range to just the left half (`count = step`).

   ```cpp
   while(count > 0) {
       auto it = first;
       auto step = count / 2;
       std::advance(it, step);

       if(*it < target) {
           first = ++it;
           count -= step + 1;
       } else {
           count = step;
       }
   }
   ```

3. **Check if Target is Found**:
   - After the loop, we check if the `first` iterator is still valid and points to the target. If the target is found, we return the index of `first` relative to the beginning of `nums`. If not, we return `-1`.

   ```cpp
   bool is_found = (!(first == last) && !(target < *first));

   if(is_found)
       return static_cast<int>(std::distance(nums.begin(), first));
   else
       return -1;
   ```

4. **Return Result**:
   - The result of the search is returned. If the target was found, we return its index; otherwise, we return `-1`.

   ```cpp
   return -1;
   ```

5. **Example Usage**:
   - In the `main` function, we test the `search` function on two cases:
     - First, searching for `9` in the vector `{-1, 0, 3, 5, 9, 12}`. The result is `4`, the index of `9`.
     - Second, searching for `2` in the same vector. Since `2` is not found, the result is `-1`.

   ```cpp
   std::cout << Solution{}.search({-1, 0, 3, 5, 9, 12}, 9) << "\n";  // Output: 4
   std::cout << Solution{}.search({-1, 0, 3, 5, 9, 12}, 2) << "\n";  // Output: -1
   ```

## Space and Time Complexity:

- **Time Complexity**: The time complexity is **O(log n)** because in each iteration of the binary search, the search space is halved. This makes it much more efficient than a linear search, especially for large inputs.
  
- **Space Complexity**: The space complexity is **O(1)**, as we only use a few additional variables for storing iterators and the count, regardless of the input size.

## Key Insights:

- **Binary Search**:
  - The binary search approach splits the search space in half at each step, reducing the problem size exponentially. This results in a time complexity of **O(log n)**, making it very efficient for large datasets.

- **Iterator Arithmetic**:
  - Instead of using explicit index-based access, iterators are used to navigate through the vector. This avoids any potential issues with manual index manipulation and provides cleaner code.

- **Efficiency**:
  - The algorithm performs a minimal number of operations to determine the presence of the target. By reducing the search space in each iteration, we ensure that the search is efficient even for large vectors.

## Final Thoughts:

This binary search solution provides an efficient method for finding the index of a target in a sorted vector with **O(log n)** time complexity and **O(1)** space complexity. It leverages iterators for cleaner code and ensures that the search is performed in the most efficient manner possible.