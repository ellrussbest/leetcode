# 132 Pattern Solution: Intuition

This solution solves the problem of detecting a 132 pattern in an array `nums`. A 132 pattern is a subsequence of three integers `i`, `j`, and `k` such that:
- `i < j < k`
- The number `j` (the middle element) is greater than `k` (the rightmost element), and the number `i` (the leftmost element) is smaller than `k`.

We explore two approaches to solving the problem: an **optimized approach** using a **stack** and a **brute-force approach** that checks all triplets.

## Optimized Approach: Using a Stack

The optimized approach uses a **stack** to track potential candidates for the middle (`j`) element, and a variable `k` to store the rightmost element of the 132 pattern. By processing the array from right to left, we can efficiently identify whether a valid 132 pattern exists.

### Step-by-Step Explanation:

1. **Initialize the Stack and `k`**:
   - We initialize an empty stack and a variable `k`, which is set to the smallest possible integer (`std::numeric_limits<int>::lowest()`) to store the rightmost element of the 132 pattern.

   ```cpp
   std::stack<int> st;
   auto k = std::numeric_limits<int>::lowest();
   ```

2. **Iterate Through the Array (Right to Left)**:
   - We iterate through the array from right to left. The current element `i` (leftmost in the potential 132 pattern) is compared to `k`. If `i` is smaller than `k`, a valid 132 pattern is found, and we return `true`.

   ```cpp
   for (auto i = nums.rbegin(); i != nums.rend(); ++i) {
       if (*i < k)
           return true;
   ```

3. **Update `k` Using the Stack**:
   - While the stack is not empty and the top element of the stack is smaller than `i`, we update `k` to be the top element of the stack and pop the stack.

   ```cpp
   while (!st.empty() && st.top() < *i) {
       k = st.top();
       st.pop();
   }
   ```

4. **Push Current Element to the Stack**:
   - We push the current element `i` to the stack. This ensures that the stack only holds elements that are greater than `k` and `i`.

   ```cpp
   st.emplace(*i);
   ```

5. **Return the Result**:
   - If no valid 132 pattern is found after iterating through the array, we return `false`.

   ```cpp
   return false;
   ```

6. **Time and Space Complexity**:
   - **Time Complexity**: The time complexity is **O(n)**, where `n` is the length of the array. Each element is processed once, and each stack operation (push and pop) takes constant time.
   - **Space Complexity**: The space complexity is **O(n)** due to the stack used to store elements.

---

## Brute-Force Approach: Checking All Triplets

The brute-force approach checks every possible triplet of indices `(i, j, k)` in the array to find a valid 132 pattern. This method is straightforward but less efficient.

### Step-by-Step Explanation:

1. **Iterate Over All Triplets**:
   - We use three nested loops to check all possible triplets `(i, j, k)` where `i < j < k`.

   ```cpp
   for (size_t i = 0; i < nums.size(); ++i) {
       for (size_t j = i + 1; j < nums.size(); ++j) {
           for (size_t k = j + 1; k < nums.size(); ++k) {
               if (nums[i] < nums[k] && nums[k] < nums[j])
                   return true;
           }
       }
   }
   ```

2. **Check Triplet Condition**:
   - For each triplet `(i, j, k)`, we check if `nums[i] < nums[k] < nums[j]`. If the condition is met, we return `true`.

3. **Return the Result**:
   - If no valid 132 pattern is found, we return `false`.

   ```cpp
   return false;
   ```

4. **Time and Space Complexity**:
   - **Time Complexity**: The time complexity is **O(n^3)**, where `n` is the length of the array. The three nested loops result in cubic time complexity.
   - **Space Complexity**: The space complexity is **O(1)**, as we do not use any extra data structures beyond the input array.

---

## Key Insights:

### Optimized Approach (Using Stack):
- **Efficiency**:
  - The stack-based solution runs in **O(n)** time, making it much more efficient than the brute-force approach, which has a time complexity of **O(n^3)**.
  
- **Stack Usage**:
  - The stack stores elements that are potential candidates for the middle element (`j`), while the variable `k` ensures we keep track of the rightmost element.

### Brute-Force Approach:
- **Simplicity**:
  - The brute-force approach is easy to implement and understand, but it checks all triplets, making it inefficient for large arrays.
  
- **Higher Time Complexity**:
  - The cubic time complexity of **O(n^3)** becomes impractical for larger datasets, limiting the scalability of this solution.

---

## Final Thoughts:

- **Optimized Approach**: The stack-based approach provides an **O(n)** time complexity, making it more efficient and better suited for larger datasets.
  
- **Brute-Force Approach**: While simple, the brute-force approach has a high time complexity of **O(n^3)**, making it unsuitable for larger arrays.

---

## Example Walkthrough:

Consider the input `nums = {3, 1, 4, 2}`:

### Optimized Approach:
- **Step 1**: Start with an empty stack and `k = -∞`.
- **Step 2**: For `nums[3] = 2`, we push `2` onto the stack.
- **Step 3**: For `nums[2] = 4`, we push `4` onto the stack.
- **Step 4**: For `nums[1] = 1`, since `1 < 2`, we update `k = 2` and pop the stack.
- **Step 5**: For `nums[0] = 3`, since `3 > 2`, we continue iterating.

- The result is `false` since no valid 132 pattern is found.

### Brute-Force Approach:
- **Step 1**: Check triplet `(3, 1, 4)` and find that `3 < 4 < 1`. No match.
- **Step 2**: Check triplet `(1, 4, 2)` and find that `1 < 2 < 4`. Match! Return `true`.

---

## Final Comparison:

- **Efficiency**: The optimized approach using a stack is significantly more efficient with **O(n)** time complexity, compared to the brute-force approach's **O(n^3)** time complexity.
  
- **Space Usage**: The brute-force solution uses **O(1)** space, while the optimized approach uses **O(n)** space to store the stack of potential middle elements.

