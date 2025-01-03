# Rotate Array Solution: Intuition

This solution rotates a vector of integers `nums` by `k` positions to the right. The core idea is to perform the rotation efficiently using C++'s built-in `std::rotate` function. The function allows shifting elements of a vector while maintaining the integrity of the array.

## Step-by-Step Explanation:

1. **Initialization**:
   - First, we ensure that `k` is within the bounds of the array length. Since rotating by `k` positions where `k` is greater than the length of the array results in repeating cycles, we calculate `k % n` (where `n` is the size of `nums`) to adjust for this.

   ```cpp
   k = (k % static_cast<int>(nums.size()));
   ```

2. **Rotation using `std::rotate`**:
   - The rotation itself is done using the C++ function `std::rotate`. This function allows rotating a range of elements efficiently by specifying the beginning and end of the range.
   - We use `rbegin()` and `rend()` to define the range in reverse order and then rotate it by `k` elements. The `next` function is used to advance the reverse iterator by `k` positions.

   ```cpp
   std::rotate(nums.rbegin(), std::next(nums.rbegin(), k), nums.rend());
   ```

3. **Return Result**:
   - After rotating the elements, the function returns the modified `nums` vector.

   ```cpp
   return nums;
   ```

4. **Overloaded Output Operator for Display**:
   - The `operator<<` is overloaded to display the vector in a readable format. This custom output function formats the vector as `{1, 2, 3, 4, ...}`.

   ```cpp
   std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
       out << "{";
       for (char sep[]{0, ' ', 0}; const auto& el : v)
           out << sep << el, sep[0] = ',';
       out << "}";
       return out;
   }
   ```

5. **Main Function**:
   - The main function demonstrates the use of the `rotate` method. It tests the solution with two example inputs:
     - Rotating the vector `{1, 2, 3, 4, 5, 6, 7}` by 3 positions.
     - Rotating the vector `{-1, -100, 3, 99}` by 2 positions.

   ```cpp
   std::cout << Solution{}.rotate({1, 2, 3, 4, 5, 6, 7}, 3) << "\n";
   std::cout << Solution{}.rotate({-1, -100, 3, 99}, 2) << "\n";
   ```

6. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)** where `n` is the size of the vector `nums`. The rotation is done in linear time since `std::rotate` performs the shift in-place.
   - **Space Complexity**: The space complexity is **O(1)** since the solution modifies the vector in-place, and no additional space is required apart from the input vector.

## Key Insights:

- **Efficient Rotation**:
  - The use of `std::rotate` is a key insight. This built-in function is optimized and works in **O(n)** time, where `n` is the number of elements in the vector.
  - By rotating the elements in reverse order, we avoid the need for manual shifting of elements, making the solution concise and efficient.

- **Modulo Operation**:
  - By applying `k % n`, we handle the case where `k` is greater than the size of the vector. This ensures that we don’t perform unnecessary full rotations.

- **In-place Modification**:
  - The solution modifies the vector `nums` in-place, achieving a space complexity of **O(1)**. This is efficient as it avoids the need for extra memory allocation.

## Final Thoughts:

This `rotate` solution efficiently rotates a vector of integers in **O(n)** time and **O(1)** space. The use of `std::rotate` simplifies the logic and makes the solution both readable and performant. By leveraging the modulo operation to handle cases where `k` is larger than the vector size, the solution is robust and optimized for various input sizes.
