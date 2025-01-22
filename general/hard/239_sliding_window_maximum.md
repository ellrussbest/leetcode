# maxSlidingWindow Solution: Intuition

This solution solves the problem of finding the maximum value in each sliding window of size `k` as it moves across the array `nums`. We explore two approaches to solving this problem: an **optimized approach** using a **deque** and a **brute-force approach** that checks each window individually.

## Optimized Approach: Using a Deque

The optimized approach uses a **deque** (double-ended queue) to efficiently keep track of the indices of elements that could be the maximum in the current sliding window. The deque is maintained in decreasing order, with the front of the deque representing the maximum element in the current window.

### Step-by-Step Explanation:

1. **Initialize Deque**:
   - We use a `std::deque<size_t>` to store indices of elements in the current sliding window. The deque is ordered such that the largest element's index is at the front.

   ```cpp
   std::deque<size_t> dq;
   ```

2. **Iterate Through the Array**:
   - The sliding window is represented by two pointers, `left` and `right`, where `left` is the starting point of the window and `right` is the current position being considered.
   - As we iterate through the array, we maintain the deque by ensuring it holds only the indices of elements that could be the maximum in the window.

   ```cpp
   for (; right < nums.size(); ++right) {
       // Remove elements outside the current window
       if (!dq.empty() && left > dq.front())
           dq.pop_front();
   ```

3. **Maintain the Order of the Deque**:
   - We remove elements from the back of the deque that are smaller or equal to the current element (`nums[right]`) because they cannot be the maximum if `nums[right]` is greater.

   ```cpp
   while (!dq.empty() && !(nums[right] < nums[dq.back()]))
       dq.pop_back();
   ```

4. **Store the Current Element's Index**:
   - We add the current element's index to the back of the deque.

   ```cpp
   dq.emplace_back(right);
   ```

5. **Update the Sliding Window**:
   - Once the window reaches the required size (`k`), we record the maximum value in the current window, which is at the front of the deque.

   ```cpp
   if (right >= window) {
       res.emplace_back(nums[dq.front()]);
       ++left;
   }
   ```

6. **Return the Result**:
   - The result is a vector of maximum values for each sliding window of size `k`.

   ```cpp
   return res;
   ```

7. **Time and Space Complexity**:
   - **Time Complexity**: The time complexity is **O(n)**, where `n` is the length of the array. Each element is added and removed from the deque at most once.
   - **Space Complexity**: The space complexity is **O(k)**, as the deque can store at most `k` elements at any time.

---

## Brute-Force Approach: Checking Each Window

The brute-force approach solves the problem by checking every sliding window of size `k` in the array and finding the maximum for each window.

### Step-by-Step Explanation:

1. **Iterate Over All Windows**:
   - We iterate over the array using a sliding window of size `k`. For each window, we compute the maximum element by checking all the elements within that window.

   ```cpp
   for (auto i = nums.begin(); i != ++std::prev(nums.end(), k); ++i) {
       int max = *i;
       for (auto j = i; j != std::next(i, k); ++j) {
           max = std::max(max, *j);
       }
       res.emplace_back(max);
   }
   ```

2. **Compute the Maximum in Each Window**:
   - For each window, we iterate through the elements and find the maximum.

3. **Return the Result**:
   - The function returns the maximum value for each sliding window of size `k`.

   ```cpp
   return res;
   ```

4. **Time and Space Complexity**:
   - **Time Complexity**: The time complexity is **O(n * k)**, where `n` is the length of the array and `k` is the window size. We need to examine each element within each window.
   - **Space Complexity**: The space complexity is **O(1)**, as no extra space is used beyond the input array.

---

## Key Insights:

### Optimized Approach (Using a Deque):
- **Efficiency**:
  - The deque-based approach allows us to efficiently maintain the maximum of the current sliding window in **O(n)** time complexity. Each element is processed at most twice (once when added and once when removed).
  
- **Sliding Window Management**:
  - The use of the deque ensures that the maximum element is always at the front, and the deque only holds relevant indices, making the solution both time-efficient and space-efficient.

### Brute-Force Approach:
- **Simplicity**:
  - The brute-force approach is simple to implement but is inefficient because it requires recalculating the maximum for each window from scratch, leading to **O(n * k)** time complexity.
  
- **Higher Time Complexity**:
  - The time complexity is **O(n * k)**, which becomes impractical for larger arrays, especially when `k` is large.

---

## Final Thoughts:

- **Optimized Approach**: The deque-based solution is far more efficient for larger arrays, providing an **O(n)** time complexity. This approach is ideal for situations where performance is critical.

- **Brute-Force Approach**: The brute-force solution is simple to implement but has a **O(n * k)** time complexity, which is inefficient for large inputs or large window sizes.

---

## Example Walkthrough:

Consider the input `nums = {1, 3, -1, -3, 5, 3, 6, 7}` and `k = 3`:

### Optimized Approach:
- **Step 1**: Start with an empty deque.
- **Step 2**: For `nums[0] = 1`, the deque is empty, so we add its index. The window expands.
- **Step 3**: For `nums[1] = 3`, the deque is updated to hold indices of elements in decreasing order, with `3` being the largest.
- **Step 4**: For `nums[2] = -1`, the deque still maintains the order. The maximum value in the window is `3` (at index `1`), and the window slides.
- **Step 5**: Continue updating the deque and finding the maximum for each sliding window.

### Brute-Force Approach:
- **Step 1**: For the window `[1, 3, -1]`, the maximum is `3`.
- **Step 2**: For the window `[3, -1, -3]`, the maximum is `3`.
- **Step 3**: Continue checking all windows and updating the results.

---

## Final Comparison:

- **Efficiency**: The deque-based approach is significantly more efficient with **O(n)** time complexity, compared to the brute-force approach with **O(n * k)** time complexity.
  
- **Space Usage**: The brute-force approach uses **O(1)** space, while the optimized approach uses **O(k)** space for the deque.

---
