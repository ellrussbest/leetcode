# Min Pair Sum Solution: Intuition

This solution aims to find the maximum sum of pairs in a list where each pair consists of one number from the beginning of the sorted array and one number from the end. The goal is to maximize the sum of these pairs, and the approach leverages sorting to pair the smallest and largest numbers.

## Step-by-Step Explanation:

1. **Sort the Array**:
   - We begin by sorting the array in non-decreasing order. This allows us to efficiently pair the smallest and largest numbers together, which will maximize the sum for each pair.

   ```cpp
   std::sort(nums.begin(), nums.end());
   ```

2. **Initialize Variables**:
   - We define two pointers:
     - `left` starts at the beginning of the array (`nums.begin()`).
     - `right` starts at the end of the array (`nums.end()`), but we adjust it in the loop.
   - We also initialize a variable `max` to keep track of the maximum sum found.

   ```cpp
   int max = 0;
   auto left = nums.begin();
   auto right = nums.end();
   ```

3. **Pair Elements**:
   - We loop through the array, pairing the smallest available element (`*left`) with the largest available element (`*right`). After each pairing:
     - We move `left` forward (increment it).
     - We move `right` backward (decrement it).
   - At each step, we update `max` with the larger of the current `max` and the sum of the current pair.

   ```cpp
   while (left != right && --right != left)
       max = std::max(max, *left++ + *right);
   ```

4. **Return Result**:
   - After all pairs have been processed, we return the largest sum stored in `max`.

   ```cpp
   return max;
   ```

5. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n log n)** because we sort the array, where `n` is the number of elements. The rest of the operations are linear in time complexity, making sorting the bottleneck.
   - **Space Complexity**: The space complexity is **O(1)** if we disregard the input array because we are only using a constant amount of extra space for variables.

## Key Insights:

- **Optimal Pairing**:
  - By sorting the array and pairing the smallest and largest numbers, we maximize the sum of each pair. This greedy approach ensures that the sum of pairs is maximized.
  
- **Efficient Pairing**:
  - The use of two pointers (`left` and `right`) ensures that we pair the elements in an efficient manner with a single traversal after sorting.

## Final Thoughts:

This solution for the "min pair sum" problem uses sorting to arrange the elements in an optimal order and efficiently pairs them using a two-pointer technique. It provides the correct result in **O(n log n)** time, making it suitable for a wide range of input sizes.
