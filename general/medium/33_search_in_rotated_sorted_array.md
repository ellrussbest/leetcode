# Search in Rotated Sorted Array: Problem Explanation and Solution

This solution efficiently searches for a target value in a rotated sorted array using binary search. The array has been rotated at an unknown pivot, and the goal is to find the index of the target or return `-1` if the target is not present.

## Problem Overview:

### Input:
- A rotated sorted array `nums` containing distinct integers.
- An integer `target` to find in the array.

### Output:
- The index of the `target` in the array if it exists, otherwise return `-1`.

For example:
- **Input**: `[4,5,6,7,0,1,2], 0`
- **Output**: `4`

- **Input**: `[4,5,6,7,0,1,2], 3`
- **Output**: `-1`

- **Input**: `[1], 0`
- **Output**: `-1`

---

## Step-by-Step Explanation:

### 1. **Partitioning the Array**:
   The first step is identifying the pivot point of the rotated sorted array. We use `std::partition_point` to find the point where the sorted array is rotated. This point helps determine which part of the array to perform the binary search on.

   ```cpp
   auto pivot = std::partition_point(std::next(nums.begin()), nums.end(), [&nums](const auto& val) {
       return *nums.begin() < val;
   });
   ```

   - `partition_point` finds the transition from the increasing part to the rotated part of the array.
   - This gives us two subarrays: one before the pivot and one after, both sorted independently.

### 2. **Binary Search**:
   The next step is to perform binary search on both parts of the array to find the target.

   - **First Search**: We apply binary search on the first part of the array (from the beginning to the pivot).
   
   ```cpp
   if(auto [it, success] = m_binary_search(nums.begin(), pivot, target); success)
       return static_cast<int>(std::distance(nums.begin(), it));
   ```

   - **Second Search**: If the target is not found in the first part, we apply binary search on the second part (from the pivot to the end).

   ```cpp
   if(auto [it, success] = m_binary_search(pivot, nums.end(), target); success)
       return static_cast<int>(std::distance(nums.begin(), it));
   ```

   If the target is found in either part, we return its index. If not, we return `-1`.

### 3. **Binary Search Helper Function**:
   The `m_binary_search` function is a custom binary search implementation that returns both the iterator to the target and a success flag indicating whether the target was found.

   ```cpp
   template <typename ForwardIt, typename T = typename std::iterator_traits<ForwardIt>::value_type>
   std::tuple<ForwardIt, bool> m_binary_search(ForwardIt first, ForwardIt last, const T& val) {
       auto it = std::lower_bound(first, last, val);
       bool is_found = (!(it == last) && !(val < *it));
       
       return {it, is_found};
   }
   ```

   - We use `std::lower_bound` to find the first element that is not less than the target. If this element is the target, the search is successful.

### 4. **Return the Result**:
   After performing the searches in both parts, the function returns the index of the target if found, otherwise `-1`.

   ```cpp
   return -1;
   ```

---

### 5. **Edge Case Handling**:
   - **Single Element**: If the array has only one element, the algorithm checks if it matches the target.
   - **Target Not Found**: If the target is not present in the array, the algorithm returns `-1`.
   - **Empty Array**: If the array is empty, the result will be `-1`.

   For example:
   - **Input**: `[1], 0`
   - **Output**: `-1`
   - **Input**: `[4,5,6,7,0,1,2], 3`
   - **Output**: `-1`

---

## Time and Space Complexity:

- **Time Complexity**:  
  The algorithm runs in **O(log n)** time, where `n` is the length of the array. The binary search in each part of the array takes logarithmic time, making the solution efficient even for large arrays.

- **Space Complexity**:  
  The space complexity is **O(1)**, as the algorithm uses a constant amount of extra space, aside from the input array.

---

## Final Thoughts:

This solution efficiently searches for a target in a rotated sorted array by utilizing binary search. The approach guarantees **O(log n)** time complexity and **O(1)** space complexity, making it suitable for large arrays. By partitioning the array at the pivot point and applying binary search to both subarrays, the solution handles the rotated nature of the array effectively.
```