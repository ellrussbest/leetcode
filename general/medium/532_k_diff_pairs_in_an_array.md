# Find Pairs Solution: Intuition

This solution aims to find the number of unique pairs `(i, j)` in the array `nums` such that the absolute difference between `nums[i]` and `nums[j]` is equal to a given value `k`. The approach leverages a hash map (unordered_map) to efficiently count the occurrences of each number and find the pairs.

## Step-by-Step Explanation:

1. **Initialization**:
   - A hash map `m_map` is used to store the frequency of each element in the input array `nums`.
   - The hash map will map each number to its frequency in the array.

   ```cpp
   std::unordered_map<int, int> m_map;
   ```

2. **Populating the Hash Map**:
   - We iterate over the input vector `nums`, inserting each number into `m_map`.
   - For each number, we use the `try_emplace` function to either insert it with a frequency of 1 or increment its frequency if it already exists.

   ```cpp
   for(const auto& num : nums) {
       auto [it, success] = m_map.try_emplace(num, 1);
       if(!success)
           ++it->second;
   }
   ```

3. **Count Valid Pairs**:
   - We then iterate over each key-value pair in the hash map.
   - If `k == 0`, we look for numbers that appear more than once, since the absolute difference between them will be zero.
   - If `k != 0`, we check if `key + k` exists in the hash map, which would form a valid pair.

   ```cpp
   int count = 0;
   for(const auto& [key, val] : m_map) {
       if(k == 0) {
           if(val > 1)
               ++count;
       } else if(m_map.find(key + k) != m_map.end())
           ++count;
   }
   ```

4. **Return Result**:
   - Finally, the total count of valid pairs is returned.

   ```cpp
   return count;
   ```

5. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)** because we loop through the array once to populate the hash map and then loop through the hash map to count valid pairs. Both operations take linear time.
   - **Space Complexity**: The space complexity is **O(n)** due to the storage required for the hash map, which in the worst case can store all unique elements of the input array.

## Key Insights:

- **Efficient Pair Search**:
  - Using an unordered map allows for constant-time lookups when checking if `key + k` exists in the map.
  
- **Handling Special Case for k == 0**:
  - When `k == 0`, the valid pairs are those where a number appears more than once in the array. The solution explicitly handles this case by checking if the frequency of a number is greater than 1.

- **Space Complexity**:
  - The space complexity is driven by the hash map that stores the frequencies of each number in the array, which is optimal for solving this problem efficiently.

## Final Thoughts:

This solution efficiently counts the number of unique pairs with the given difference `k` in **O(n)** time and **O(n)** space. By using an unordered map for frequency counting and checking for valid pairs, the solution is both time-efficient and easy to understand. The edge case when `k == 0` is handled separately to ensure correctness.
