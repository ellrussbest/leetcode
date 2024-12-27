# twoSum Solution: Intuition

This solution solves the problem of finding two indices in an array `nums` such that the numbers at those indices sum up to a given `target`. We explore two approaches to solving the problem: an **optimized approach** using a hash map and a **brute-force approach** that checks all pairs.

## Optimized Approach: Using an Unordered Map

The optimized solution utilizes an **unordered_map** to store previously visited numbers and their corresponding indices. For each number, the algorithm checks if the complement (i.e., `target - current_number`) is already in the map. If the complement exists, it means we have found two numbers that sum up to the target.

### Step-by-Step Explanation:

1. **Initialize Unordered Map**:
   - We use an unordered map `m_map` to store the numbers encountered so far, along with their indices.

   ```cpp
   std::unordered_map<int, size_t> m_map;
   ```

2. **Iterate Through the Array**:
   - We iterate through the array `nums` and for each number, we calculate the complement (`target - nums[i]`).
   - If the complement is found in the map, it means we have a pair of numbers that add up to `target`. We return the indices of these two numbers.

   ```cpp
   if (auto it = m_map.find(nums[i]); it != m_map.end())
       return {static_cast<int>(it->second), static_cast<int>(i)};
   ```

3. **Store Complement in the Map**:
   - If the complement is not found, we store the current number and its index in the map for future reference.

   ```cpp
   auto complement = target - nums[i];
   m_map.try_emplace(complement, i);
   ```

4. **Return the Result**:
   - The result will be the indices of the two numbers that add up to the target. If no such pair is found, we return an empty vector.

   ```cpp
   return {};
   ```

5. **Time and Space Complexity**:
   - **Time Complexity**: The time complexity is **O(n)**, where `n` is the length of the array. We iterate through the array once, and each map operation (insert and find) takes constant time.
   - **Space Complexity**: The space complexity is **O(n)**, as we store up to `n` elements in the unordered map.

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

### Optimized Approach (Using Unordered Map):

- **Efficiency**:
  - The use of an unordered map enables us to reduce the time complexity to **O(n)**, making the solution much more efficient compared to brute-force.
  
- **Constant Time Lookups**:
  - The unordered map provides **constant-time lookups** for the complement of the current number, ensuring fast identification of valid pairs.

### Brute-Force Approach:

- **Simplicity**:
  - The brute-force approach is simple and straightforward, as it simply checks every pair of numbers. However, this approach is inefficient for large arrays because it involves nested loops.

- **Higher Time Complexity**:
  - The time complexity is **O(n^2)**, which is inefficient for large inputs, making this approach impractical for bigger data sets.

---

## Final Thoughts:

- **Optimized Approach**: The hash map-based solution is the preferred approach for large inputs due to its **O(n)** time complexity and **O(n)** space complexity. It provides a significant improvement in performance.
  
- **Brute-Force Approach**: The brute-force solution works but is highly inefficient for large arrays, with a time complexity of **O(n^2)**. It is only suitable for small arrays.

---

## Example Walkthrough:

Consider the input `nums = {2, 7, 11, 15}` and `target = 9`:

### Optimized Approach:

- **Step 1**: We start with an empty map.
- **Step 2**: The first number is `2`. The complement is `9 - 2 = 7`. The map is empty, so we store `7` in the map with the index `0`.
- **Step 3**: The second number is `7`. The complement is `9 - 7 = 2`. We find `2` in the map at index `0`. We return the indices `{0, 1}`.

### Brute-Force Approach:

- **Step 1**: We start by checking all pairs:
  - `2 + 7 = 9`. We return indices `{0, 1}`.

---

## Final Comparison:

- **Efficiency**: The optimized approach using an unordered map is significantly more efficient, with **O(n)** time complexity, compared to the brute-force approach which has **O(n^2)** time complexity.
  
- **Space Usage**: The brute-force solution uses **O(1)** space, while the optimized approach uses **O(n)** space to store the map of previously visited numbers.

