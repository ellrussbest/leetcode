# twoSum Solution: Intuition

This solution solves the problem of finding two indices in an array `nums` such that the numbers at those indices sum up to a given `target`. We explore two approaches to solving the problem: an **optimized approach** using a **map** and a **brute-force approach** that checks all pairs.

## Optimized Approach: Using a Map with `lower_bound`

The optimized solution uses a **map** (sorted associative container) to store previously visited numbers and their corresponding indices. This allows us to efficiently find the complement of each number (i.e., `target - current_number`) in a sorted order. The key difference in this approach is using `lower_bound` to quickly locate the position where the complement could be inserted, and comparing values to identify pairs that sum up to the target.

### Step-by-Step Explanation:

1. **Initialize Map**:
   - We use a `std::map<int, size_t>` to store the complement of each number along with its index. The map automatically sorts the keys in ascending order.

   ```cpp
   std::map<int, size_t> m_map;
   ```

2. **Iterate Through the Array**:
   - For each number in the array, we attempt to find its complement (`target - nums[i]`) by using `lower_bound`. This function returns an iterator pointing to the first element that is not less than the given value, which helps locate where the complement might be.
   
   ```cpp
   auto it = m_map.lower_bound(nums[i]);
   ```

3. **Check for Complement**:
   - If `lower_bound` returns an element in the map and the element is equal to the current number (`nums[i]`), we have found a pair that sums to the target. The algorithm returns the indices of the two numbers that sum up to the target.

   ```cpp
   if (it != m_map.end() && !(nums[i] < it->first))
       return {static_cast<int>(it->second), static_cast<int>(i)};
   ```

4. **Store Complement in Map**:
   - If no valid complement is found, we efficiently store the current number and its index in the map using the **it** as the hint, allowing us to look for it in future iterations.

   ```cpp
   auto complement = target - nums[i];
   m_map.emplace_hint(it, complement, i);
   ```

5. **Return the Result**:
   - The result is the pair of indices that sum up to the target. If no such pair is found, an empty vector is returned.

   ```cpp
   return {};
   ```

6. **Time and Space Complexity**:
   - **Time Complexity**: The time complexity is **O(n log n)**, where `n` is the length of the array. For each number, we perform a `lower_bound` operation on the map, which takes logarithmic time.
   - **Space Complexity**: The space complexity is **O(n)**, as we store up to `n` elements in the map.

---

## Brute-Force Approach: Checking All Pairs

The brute-force approach solves the same problem by checking all possible pairs of numbers in the array to find the two that sum up to the target.

### Step-by-Step Explanation:

1. **Iterate Over All Pairs**:
   - We use two nested loops to check every possible pair of numbers in the array. The outer loop (`i`) defines the first number, and the inner loop (`j`) defines the second number.

   ```cpp
   for (size_t i = 0; i < nums.size(); ++i) {
       for (size_t j = i + 1; j < nums.size(); ++j) {
           if (nums[i] + nums[j] == target)
               return {static_cast<int>(i), static_cast<int>(j)};
       }
   }
   ```

2. **Check Pair Sum**:
   - For each pair `(i, j)`, we check if `nums[i] + nums[j]` equals the target. If it does, we return the indices of these two numbers.

3. **Return the Result**:
   - The function returns the indices of the pair of numbers that sum up to the target. If no such pair is found, it returns an empty vector.

   ```cpp
   return {};
   ```

4. **Time and Space Complexity**:
   - **Time Complexity**: The time complexity is **O(n^2)**, where `n` is the length of the array. We have to check every pair, resulting in a quadratic time complexity.
   - **Space Complexity**: The space complexity is **O(1)** since no additional space is used beyond the input array.

---

## Key Insights:

### Optimized Approach (Using Map with `lower_bound`):
- **Efficiency**:
  - By leveraging the map’s sorted structure, we reduce the time complexity to **O(n log n)**, which is more efficient than brute-force.
  
- **Sorted Lookups**:
  - The use of `lower_bound` ensures efficient searching for the complement, enabling the algorithm to quickly identify valid pairs.

### Brute-Force Approach:
- **Simplicity**:
  - The brute-force approach is simple and easy to implement, but it checks all pairs, which makes it inefficient for large arrays.

- **Higher Time Complexity**:
  - The time complexity is **O(n^2)**, which becomes impractical for larger inputs, limiting the scalability of this solution.

---

## Final Thoughts:

- **Optimized Approach**: The map-based solution using `lower_bound` provides an **O(n log n)** time complexity, which is a significant improvement over the brute-force approach. It’s better suited for larger datasets.

- **Brute-Force Approach**: While the brute-force solution is conceptually simple and works for small arrays, it becomes inefficient for large arrays with a time complexity of **O(n^2)**.

---

## Example Walkthrough:

Consider the input `nums = {2, 7, 11, 15}` and `target = 9`:

### Optimized Approach:
- **Step 1**: Start with an empty map.
- **Step 2**: For `nums[0] = 2`, the complement is `9 - 2 = 7`. We insert `7` into the map.
- **Step 3**: For `nums[1] = 7`, the complement is `9 - 7 = 2`. We find `2` in the map and return the indices `{0, 1}`.

### Brute-Force Approach:
- **Step 1**: Check pairs `(2, 7)` and find that `2 + 7 = 9`. Return indices `{0, 1}`.

---

## Final Comparison:

- **Efficiency**: The optimized approach using a map with `lower_bound` is more efficient, with **O(n log n)** time complexity, compared to the brute-force approach, which has **O(n^2)** time complexity.
  
- **Space Usage**: The brute-force solution uses **O(1)** space, while the optimized approach uses **O(n)** space to store the map of previously visited numbers.
