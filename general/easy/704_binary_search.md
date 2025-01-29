# Binary Search Solution

This solution uses the `std::lower_bound` function from the C++ Standard Library to find the index of a `target` value in a sorted vector `nums`. If the target exists in the vector, its index is returned. If the target is not found, `-1` is returned.

## Step-by-Step Explanation:

1. **Using `std::lower_bound`**:
   - `std::lower_bound` is used to find the first element that is **not less than** the target value. It returns an iterator pointing to the target if it's found, or to the position where the target should be inserted if it doesn't exist.
   
   ```cpp
   auto it = std::lower_bound(nums.begin(), nums.end(), target);
   ```
   
   - The iterator `it` will either:
     - Point to the target value if it exists in the vector.
     - Point to the first element larger than the target, or `nums.end()` if no such element exists.

2. **Checking if the Target Exists**:
   - After finding the iterator with `std::lower_bound`, we check if:
     - The iterator equals `nums.end()`, indicating the target is greater than all elements in the vector.
     - The target is less than the element pointed to by the iterator.
   
   ```cpp
   if(it == nums.end() || target < *it)
       return -1;
   ```

   - If either condition is true, the target isn't present, and `-1` is returned. If neither condition is true, the iterator points to the target, and we proceed to the next step.

3. **Returning the Index**:
   - If the target is found, we compute its index by calculating the distance from the beginning of the vector to the iterator using `std::distance`.
   
   ```cpp
   return static_cast<int>(std::distance(nums.begin(), it));
   ```

4. **Example Usage**:
   - The `main` function demonstrates how to use the `search` method:
     - Searching for `9` in the vector `{-1, 0, 3, 5, 9, 12}` returns `4` since `9` is located at index `4`.
     - Searching for `2` in the same vector returns `-1` since `2` is not present.

   ```cpp
   std::cout << Solution{}.search({-1, 0, 3, 5, 9, 12}, 9) << "\n";  // Output: 4
   std::cout << Solution{}.search({-1, 0, 3, 5, 9, 12}, 2) << "\n";  // Output: -1
   ```

## Space and Time Complexity:

- **Time Complexity**: The time complexity is **O(log n)** due to the underlying binary search implemented by `std::lower_bound`. This makes the search process efficient even for large datasets.
  
- **Space Complexity**: The space complexity is **O(1)** since the algorithm only uses a few variables for the iterator and index calculation, regardless of the size of the input.

## Key Insights:

- **Efficient Search**: `std::lower_bound` performs a binary search internally, allowing for fast searching with a time complexity of **O(log n)**.
  
- **Iterator-Based Access**: By using iterators and `std::distance`, this solution avoids the need for direct index manipulation, which can lead to cleaner and safer code.

- **Simpler Code**: This approach significantly simplifies the implementation by leveraging a built-in C++ function for binary search rather than manually handling the logic.

## Final Thoughts:

This solution provides a concise and efficient way to search for a target in a sorted vector using **O(log n)** time complexity and **O(1)** space complexity. By utilizing `std::lower_bound`, we simplify the code while maintaining performance and ensuring correctness.