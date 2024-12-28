# containsDuplicate Solution: Intuition

This solution determines if a given vector `nums` contains any duplicate values. The approach uses sorting to bring duplicate values next to each other and then utilizes the `std::unique` function to identify if duplicates exist.

## Optimized Approach: Using Sorting and `std::unique`

The optimized solution works by first sorting the input array. Once sorted, duplicates will be placed next to each other. The `std::unique` function then removes adjacent duplicates, leaving only the first occurrence of each element. If the size of the array changes after calling `std::unique`, it indicates that duplicates were found.

### Step-by-Step Explanation:

1. **Sort the Array**:
   - We begin by sorting the array `nums`. Sorting brings any duplicates next to each other, which simplifies the identification of duplicates.

   ```cpp
   std::sort(nums.begin(), nums.end());
   ```

2. **Remove Adjacent Duplicates**:
   - The `std::unique` function removes all adjacent duplicates in the sorted array. It returns an iterator to the end of the unique portion of the array. The elements after this iterator are still in their original positions but are now considered "removed."

   ```cpp
   auto it = std::unique(nums.begin(), nums.end());
   ```

3. **Check for Duplicates**:
   - After applying `std::unique`, if the iterator `it` is not equal to `nums.end()`, it means there are duplicates in the array. This indicates that at least one duplicate was found.

   ```cpp
   return it != nums.end();
   ```

4. **Return the Result**:
   - The function returns `true` if duplicates are found and `false` otherwise.

   ```cpp
   return it != nums.end();
   ```

5. **Time and Space Complexity**:
   - **Time Complexity**: The time complexity is **O(n log n)**, where `n` is the length of the array. The dominant factor is the sorting step, which takes **O(n log n)** time. The `std::unique` function operates in linear time **O(n)**, but sorting dominates.
   - **Space Complexity**: The space complexity is **O(1)**, as no extra space is used beyond the input array (excluding the space used by sorting).

---

## Key Insights:

### Efficiency of the Approach:
- **Sorting** brings elements with duplicates together, simplifying the detection of duplicates.
- **`std::unique`** effectively reduces the array by removing adjacent duplicates in **O(n)** time.
- The overall complexity is **O(n log n)** due to sorting, which is efficient enough for most scenarios.

---

## Example Walkthrough:

Consider the input `nums = {1, 2, 3, 1}`:

### Step-by-Step Execution:

1. **Step 1**: Sort the array. After sorting, `nums` becomes `{1, 1, 2, 3}`.
2. **Step 2**: Apply `std::unique`. It will move the second `1` next to the first `1` and return an iterator pointing to the unique part of the array.
3. **Step 3**: Since the iterator is not equal to `nums.end()`, it means there are duplicates, and the function returns `true`.

For `nums = {1, 2, 3, 4}`:

1. After sorting, the array remains `{1, 2, 3, 4}`.
2. `std::unique` does not change the array, indicating no duplicates.
3. The function returns `false`.

---

## Final Thoughts:

- **Optimized Approach**: Sorting the array and using `std::unique` provides an efficient and straightforward solution for detecting duplicates, with an overall time complexity of **O(n log n)**.
  
- **Use Case**: This solution is suitable for arrays where the size is moderate and sorting is acceptable. The **O(n log n)** time complexity makes it efficient for most use cases.

--- 

## Example Usage:

```cpp
std::cout << std::boolalpha;
std::cout << Solution{}.containsDuplicate({1, 2, 3, 1}) << "\n";  // Output: true
std::cout << Solution{}.containsDuplicate({1, 2, 3, 4}) << "\n";  // Output: false
std::cout << Solution{}.containsDuplicate({1, 1, 1, 3, 3, 4, 3, 2, 4, 2}) << "\n";  // Output: true
```

---

This approach efficiently identifies duplicates using sorting and a linear pass to remove adjacent duplicates, providing an elegant solution to the problem.