# Merge Sorted Arrays: Intuition

This solution merges two sorted arrays `nums1` and `nums2` into a single sorted array. It utilizes an efficient approach with the **lower bound** and **shifting** techniques to maintain the sorted order while minimizing the number of operations.

## Step-by-Step Explanation:

### 1. **Initial Setup**:
   - The first array, `nums1`, has enough space to accommodate all elements from both `nums1` and `nums2`. The variable `m` represents the number of elements in the original `nums1`, while `n` represents the number of elements in `nums2`.
   - We begin by setting `last` to point to the end of the valid elements in `nums1`, which are the first `m` elements.

   ```cpp
   auto last = nums1.begin() + m;
   ```

### 2. **Iterate Over `nums2`**:
   - For each element in `nums2`, we find its correct position in `nums1` using `std::lower_bound`. This function performs a binary search to find the first position where the element can fit in the sorted order.
   - If the position is equal to `last`, it means the element should be appended to the end of the current valid portion of `nums1`.
   
   ```cpp
   auto it = std::lower_bound(nums1.begin(), last, num);
   if (it == last)
       *it = num;
   ```

### 3. **Shifting Elements**:
   - If the element is not placed at the end, we need to shift the elements in `nums1` to make room for the new element. The `shift` function takes care of moving elements from `it` to `last` to the right by one position.
   
   ```cpp
   else {
       shift(it, last);
       *it = num;
   }
   ```

   - The `shift` function shifts elements to the right by iterating backward from `last` to `first` and moving each element to the next position.

   ```cpp
   template <typename BidirIt>
   void shift(BidirIt first, BidirIt last) {
       auto prev = std::prev(last);

       while (last != first) {
           *last = std::move(*prev);
           --last, --prev;
       }
   }
   ```

### 4. **Return the Merged Array**:
   - After processing all elements from `nums2`, the merged result is stored in `nums1`, which is then returned.

   ```cpp
   return nums1;
   ```

## Key Insights:

- **Lower Bound**:  
  The `std::lower_bound` function helps find the correct position in the sorted portion of `nums1` for each element in `nums2` in logarithmic time, ensuring efficient placement of elements.

- **Efficient Shifting**:  
  The `shift` function handles the rearrangement of elements in `nums1` without requiring additional space. It efficiently shifts elements one by one from the back of the array to the front to make space for new elements.

- **Edge Case Handling**:
  - The solution handles edge cases such as when `nums2` is empty (no elements to merge) or when `nums1` is empty (all elements come from `nums2`).
  - It also handles cases where `nums1` is already fully populated or when `nums2` has fewer elements than `nums1`.

- **Time and Space Complexity**:
  - **Time Complexity**: The algorithm runs in **O(n*m)** time because for each element in `nums2`, we perform a `std::lower_bound` operation on `nums1`, which takes **O(log m)** time, and the total number of such operations is **n**.
  - **Space Complexity**: The space complexity is **O(1)**, as the algorithm modifies `nums1` in place without using additional data structures.

## Final Thoughts:

This solution efficiently merges two sorted arrays using a combination of the **lower bound** and **shifting** techniques. It optimizes the insertion of elements from `nums2` into `nums1`, making it both time-efficient and space-efficient. The approach handles a variety of edge cases and ensures that the final merged array is sorted without requiring additional memory allocation.
