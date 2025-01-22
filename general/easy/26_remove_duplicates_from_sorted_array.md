# removeDuplicates Solution: Intuition

This solution removes duplicates from a sorted vector of integers `nums`. The solution uses the `std::unique` function from the C++ Standard Library to efficiently eliminate adjacent duplicates in-place and returns the new length of the vector with unique elements.

## Step-by-Step Explanation:

1. **Use `std::unique` to Remove Duplicates**:
   - The `std::unique` function is applied to the vector `nums`. It rearranges the elements in `nums` such that each element appears only once consecutively, and returns an iterator pointing to the end of the unique elements.
   - The elements beyond this iterator are considered duplicates and are left in the vector, but are not part of the result.
   - `std::unique` operates in **O(n)** time, where `n` is the number of elements in `nums`.

   ```cpp
   auto it = std::unique(nums.begin(), nums.end());
   ```

2. **Calculate the New Length**:
   - To determine the new length of the vector after removing duplicates, we compute the distance between the beginning of the vector and the iterator returned by `std::unique`. This distance gives the number of unique elements in the vector.
   
   ```cpp
   return static_cast<int>(std::distance(nums.begin(), it));
   ```

3. **Return the Result**:
   - The function returns the number of unique elements as an integer.

4. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)**, where `n` is the length of the input vector `nums`. The `std::unique` function processes each element of the vector at most once.
   - **Space Complexity**: The space complexity is **O(1)** because `std::unique` operates in-place and does not require additional space other than a few temporary variables.

## Key Insights:

- **Efficient Duplicate Removal**:
  - The solution leverages the built-in `std::unique` function, which is specifically optimized to remove consecutive duplicates in a sorted container. This avoids the need for manually iterating and checking each element.
  
- **In-Place Operation**:
  - `std::unique` operates in-place and does not allocate additional memory beyond the input vector, making this solution space-efficient.
  
- **Distance Calculation**:
  - The use of `std::distance` allows us to easily compute the number of unique elements without needing to manually count or resize the vector.

## Final Thoughts:

This solution efficiently removes duplicates from a sorted vector in **O(n)** time and **O(1)** space. By using `std::unique`, the solution avoids unnecessary complexity and leverages C++ Standard Library functions for both clarity and performance. The solution is compact and effective, especially when working with sorted data.