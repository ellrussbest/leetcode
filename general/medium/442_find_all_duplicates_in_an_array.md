# findDuplicates Solution: Intuition

This solution identifies and returns the duplicate numbers in an input array `nums`. The idea is to use the array itself to mark the presence of numbers by modifying the sign of the elements, which avoids the need for additional space for bookkeeping.

## Step-by-Step Explanation:

1. **Initialization**:
   - We create an empty vector `res` to store the result, which will contain the duplicates.
   - We loop through each element in `nums` and process them in place, modifying the array to track the indices we've visited.

   ```cpp
   std::vector<int> res;
   for(size_t i = 0; i < nums.size(); ++i) {
       int idx = std::abs(nums[i]) - 1;
       auto N = static_cast<size_t>(idx);
   }
   ```

2. **Identifying Duplicates**:
   - For each number `nums[i]`, we calculate the index `idx = std::abs(nums[i]) - 1`, which represents the position that should be marked.
   - If `nums[N]` is negative, it indicates the number has been seen before, so we add it to the result vector `res`.
   - If `nums[N]` is positive, we multiply `nums[N]` by `-1` to mark it as visited.

   ```cpp
   if(nums[N] < 0)
       res.emplace_back(std::abs(nums[i]));
   else
       nums[N] *= -1;
   ```

3. **Return Result**:
   - Once the loop is complete, we return the vector `res`, which contains the duplicates found in the array.

   ```cpp
   return res;
   ```

4. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)** because we loop through the array once, and each operation inside the loop takes constant time.
   - **Space Complexity**: The space complexity is **O(1)** because we do not use any additional data structures apart from the result vector (which is output, not auxiliary space).

## Key Insights:

- **Using In-place Modification**:
  - The solution efficiently uses the input array `nums` to track visited elements by marking them with negative values. This avoids the need for extra space (like a set or hash table).

- **Efficient Absolute Value Calculation**:
  - The absolute value of the current element is used to determine the index of the number to mark, which ensures no data is overwritten during the process.

- **Handling Duplicates**:
  - The duplicate detection happens as we encounter a negative value at the calculated index, indicating the number has already been seen.

## Final Thoughts:

This `findDuplicates` solution is highly efficient, running in **O(n)** time and **O(1)** space (ignoring the output), making it an optimal solution for finding duplicates in an array. It cleverly uses the input array itself to store intermediate results, avoiding additional memory overhead.
