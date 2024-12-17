# Find Minimum in Rotated Sorted Array Solution: Intuition

This solution finds the minimum element in a rotated sorted array `nums`. The array is originally sorted in increasing order, but has been rotated at some pivot unknown to us. The goal is to identify the minimum element efficiently.

## Step-by-Step Explanation:

1. **Initialization**:
   - We start by obtaining the first element of the array (`first`), which is used as a reference to determine where the rotation occurred. 
   
   ```cpp
   const auto& first = *nums.begin();
   ```

2. **Using `std::partition_point`**:
   - We use the `std::partition_point` algorithm to find the point in the array where the order of elements changes from ascending to descending, which is where the rotation occurs.
   - The function `std::partition_point` takes two iterators (`std::next(nums.begin())` and `nums.end()`) and a predicate that checks whether the elements are greater than the first element (`first`). It returns an iterator pointing to the first element that is not greater than the `first` element.

   ```cpp
   auto it = std::partition_point(
       std::next(nums.begin()), nums.end(),
       [first](const auto& val) { return first < val; });
   ```

3. **Check the Rotation**:
   - After `std::partition_point` is executed, we check if `it` is equal to `nums.end()`. If `it` equals `nums.end()`, this means the array was not rotated, and the minimum element is simply the first element (`*nums.begin()`).
   - Otherwise, the iterator `it` points to the minimum element, which is returned as the result.

   ```cpp
   if (it == nums.end())
       return *nums.begin();
   else
       return *it;
   ```

4. **Return Result**:
   - The minimum element is returned either from the beginning of the array or at the point where the order changes due to rotation.

   ```cpp
   return *it;
   ```

5. **Example Usage**:
   - In the `main` function, we test the `findMin` function on several cases:
     - First, the rotated array `{3, 4, 5, 1, 2}`, where the minimum is `1`.
     - Second, the rotated array `{4, 5, 6, 7, 0, 1, 2}`, where the minimum is `0`.
     - Third, the non-rotated array `{11, 13, 15, 17}`, where the minimum is `11`.
     - Fourth, a small rotated array `{2, 1}`, where the minimum is `1`.

   ```cpp
   std::cout << Solution{}.findMin({3, 4, 5, 1, 2}) << "\n";  // Output: 1
   std::cout << Solution{}.findMin({4, 5, 6, 7, 0, 1, 2}) << "\n";  // Output: 0
   std::cout << Solution{}.findMin({11, 13, 15, 17}) << "\n";  // Output: 11
   std::cout << Solution{}.findMin({2, 1}) << "\n";  // Output: 1
   ```

## Space and Time Complexity:

- **Time Complexity**: The time complexity is **O(log n)**, as `std::partition_point` operates in logarithmic time. This is efficient for large arrays.
  
- **Space Complexity**: The space complexity is **O(1)** because no extra space is used apart from a few variables.

## Key Insights:

- **Efficient Use of `std::partition_point`**:
  - The algorithm efficiently identifies the minimum element by leveraging the `std::partition_point` algorithm, which helps locate the point of rotation in logarithmic time.

- **Optimized for Rotated Arrays**:
  - By taking advantage of the fact that the array is rotated but still sorted in parts, this approach minimizes the number of comparisons needed to identify the minimum.

- **Space Efficiency**:
  - The solution operates in **O(1)** space, meaning it does not require any additional space proportional to the input size, making it highly efficient in terms of memory usage.

## Final Thoughts:

This solution finds the minimum element in a rotated sorted array in **O(log n)** time and **O(1)** space, making it highly efficient. It leverages the standard library's `std::partition_point` to optimize the search for the minimum element, ensuring minimal overhead and fast execution, even for large datasets.
