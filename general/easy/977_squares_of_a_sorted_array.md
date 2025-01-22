# sortedSquares Solution: Intuition

This solution takes a sorted vector of integers `nums` and returns a new vector where each number is squared and the result is sorted in non-decreasing order. The approach utilizes a two-pointer technique to efficiently square the numbers and place them in the correct position without the need for sorting afterward.

## Step-by-Step Explanation:

1. **Initialization**:
   - A result vector `res` of the same size as `nums` is created and initialized with zeros.
   - Two pointers are used: `left` pointing to the beginning of `nums` and `right` pointing to the end (using reverse iterators).
   - The index `i` is initialized to the last index of the `res` vector to start filling from the largest position.

   ```cpp
   std::vector<int> res(nums.size(), 0);
   auto left = nums.begin();
   auto right = nums.rbegin();
   size_t i = res.size() - 1;
   ```

2. **Iterate and Compare Absolute Values**:
   - A while loop runs as long as the distance between `left` and `right` is greater than 0, meaning there are still elements to compare.
   - Inside the loop, we compare the absolute values of the numbers pointed to by `left` and `right`. The larger absolute value is squared and placed at the current index `i` of the `res` vector.
   - The pointer corresponding to the larger value is then moved inward (increment `left` or increment `right`), and the index `i` is decremented to fill the next largest position.

   ```cpp
   while(std::distance(left, right.base()) > 0) {
       if(std::abs(*left) > std::abs(*right))
           res[i--] = *left * *left++;
       else
           res[i--] = *right * *right++;
   }
   ```

3. **Return Result**:
   - After the loop completes, the `res` vector, which now contains the squares of the numbers from `nums` sorted in non-decreasing order, is returned.

4. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)**, where `n` is the length of the input vector `nums`. The algorithm only requires a single pass over the input vector to construct the result.
   - **Space Complexity**: The space complexity is **O(n)** because we store the result in a new vector of the same size as `nums`.

## Key Insights:

- **Two-Pointer Technique**:
  - The solution efficiently uses two pointers (`left` and `right`) to traverse `nums` from both ends and place squared values in their correct positions. This avoids the need for additional sorting.
  
- **Efficient Squaring**:
  - The comparison is based on the absolute values of the numbers, ensuring that we are always placing the largest squares at the correct position.

- **Space Complexity**:
  - The space complexity is **O(n)** because we need to store the result in a new vector `res`, which has the same size as the input.

## Final Thoughts:

The solution calculates the sorted squares of the input vector in **O(n)** time and **O(n)** space. The two-pointer approach ensures that the solution is both time-efficient and space-efficient, handling the problem with minimal computational overhead. This method is particularly effective for problems involving sorted arrays or lists.