# Sort Array Solution: Intuition

This solution sorts an array of integers using the **Merge Sort** algorithm. Merge Sort is a **divide and conquer** algorithm that splits the array into smaller subarrays, sorts them recursively, and then merges them back together. This solution leverages C++'s standard library to implement this algorithm efficiently.

## Step-by-Step Explanation:

1. **Sorting Method**:
   - The `sortArray` function takes an rvalue reference to a vector (`std::vector<int>&& nums`), allowing it to take ownership of the passed array. It calls the `merge_sort` function to sort the array.
   
   ```cpp
   std::vector<int> sortArray(std::vector<int>&& nums) {
       merge_sort(nums.begin(), nums.end());
       return nums;
   }
   ```

2. **Merge Sort Function**:
   - The `merge_sort` function is a recursive function that sorts a range of elements between `first` and `last`:
     - It calculates the distance between the two iterators (`first` and `last`).
     - If the distance is `1` or less, the subarray is already sorted, and the function returns.
     - Otherwise, it calculates the middle point of the range and recursively sorts the left and right halves.
     - After sorting both halves, it merges them using `std::inplace_merge` to combine them in sorted order.
   
   ```cpp
   template <typename BidirIt>
   void merge_sort(BidirIt first, BidirIt last) {
       auto dist = std::distance(first, last);
       if (dist <= 1)
           return;
       
       auto middle = std::next(first, dist / 2);
       merge_sort(first, middle);
       merge_sort(middle, last);
       std::inplace_merge(first, middle, last);
   }
   ```

3. **Merge Operation**:
   - The `std::inplace_merge` function is used to merge the two sorted halves (`first` to `middle` and `middle` to `last`) back into the original range, ensuring the entire range is sorted.

4. **Returning the Sorted Array**:
   - After the merge sort is complete, the sorted array (`nums`) is returned to the caller.

   ```cpp
   return nums;
   ```

5. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n log n)** because the algorithm divides the array in half recursively and merges the sorted halves in linear time.
   - **Space Complexity**: The space complexity is **O(n)** due to the recursive call stack and the temporary storage required for merging.

## Key Insights:

- **Merge Sort Characteristics**:
  - Merge Sort is an efficient, stable sorting algorithm with **O(n log n)** time complexity. It guarantees this time complexity even in the worst case, unlike algorithms like QuickSort, which can degrade to **O(n²)** in some scenarios.
  
- **Divide and Conquer**:
  - The algorithm uses the divide-and-conquer approach, which recursively breaks the problem into smaller subproblems, making it highly suitable for large datasets.

- **Inplace Merge**:
  - The `std::inplace_merge` function ensures that the merge operation occurs without requiring additional space for the merged result, which optimizes memory usage.

## Final Thoughts:

This solution efficiently sorts an array using **Merge Sort**, which guarantees **O(n log n)** time complexity in all cases. By leveraging C++'s standard library, the implementation is both efficient and clean. Merge Sort's stable sorting and predictable time complexity make it a reliable choice for large datasets, though it requires additional space due to the recursive nature of the algorithm.
