# Flower Placement Solution: Intuition

This solution determines if it's possible to plant `n` flowers in a flowerbed represented by a vector `flowerbed`, such that no two flowers are planted next to each other. The flowerbed contains `0` for empty spots and `1` for spots already occupied by flowers.

## Step-by-Step Explanation:

1. **Edge Case Check**:
   - If `n` is `0`, it means no flowers need to be planted, so we can immediately return `true`.

   ```cpp
   if (n == 0) return true;
   ```

2. **Iterating Through the Flowerbed**:
   - We use an iterator to loop through each position in the flowerbed.
   - For each position:
     - **Left and Right Neighbors**: We check if both the left and right neighbors (if they exist) are empty (`0`), and the current position is also empty.
     - If all conditions are satisfied, we "plant" a flower by setting the current position to `1`, and reduce the number of flowers (`n`) to be planted.
   
   ```cpp
   for (auto it = flowerbed.begin(); it != flowerbed.end(); ++it) {
       auto left = std::make_reverse_iterator(it);
       auto right = std::next(it);

       if (*it == 0 && (left == flowerbed.rend() || *left == 0) &&
           (right == flowerbed.end() || *right == 0)) {
           *it = 1;
           --n;

           if (n == 0) break;
       }
   }
   ```

3. **Check if All Flowers Are Planted**:
   - After iterating through the flowerbed, we check if all `n` flowers were successfully planted. If `n` is `0`, it means we were able to plant all flowers; otherwise, we return `false`.

   ```cpp
   return n == 0;
   ```

4. **Return Result**:
   - The function returns `true` if all flowers were planted according to the rules; otherwise, it returns `false`.

   ```cpp
   return n == 0;
   ```

5. **Example Usage**:
   - In the `main` function, we test the `canPlaceFlowers` function with three different cases:
     - First, trying to plant `1` flower in `{1, 0, 0, 0, 1}`, the result is `true`.
     - Second, trying to plant `2` flowers in the same flowerbed, the result is `false` (since there isn't enough space).
     - Third, trying to plant `1` flower in `{0, 0, 1, 0, 0}`, the result is `true` (there is enough space).

   ```cpp
   std::cout << std::boolalpha;
   std::cout << Solution{}.canPlaceFlowers({1, 0, 0, 0, 1}, 1) << "\n";  // Output: true
   std::cout << Solution{}.canPlaceFlowers({1, 0, 0, 0, 1}, 2) << "\n";  // Output: false
   std::cout << Solution{}.canPlaceFlowers({0, 0, 1, 0, 0}, 1) << "\n";  // Output: true
   ```

## Space and Time Complexity:

- **Time Complexity**: The time complexity is **O(n)**, where `n` is the number of positions in the flowerbed. We iterate through each position at most once.

- **Space Complexity**: The space complexity is **O(1)**, as only a few additional variables for the iterator and conditions are used, regardless of the input size.

## Key Insights:

- **Neighbor Checking**: For each position in the flowerbed, we check both the left and right neighbors to ensure no two flowers are placed next to each other. This ensures the solution is correct while iterating through the flowerbed.

- **Edge Case Handling**: The edge case of `n == 0` is handled early, which immediately optimizes the solution for cases where no flowers need to be planted.

- **Efficient Iteration**: We use iterators to traverse through the flowerbed, making the code more concise and easier to understand.

## Final Thoughts:

This solution efficiently determines whether it's possible to plant `n` flowers in a flowerbed following the given rules. With a **O(n)** time complexity and **O(1)** space complexity, the solution is both time and space efficient. The logic ensures that flowers are placed only where permitted, making the approach robust and reliable.
