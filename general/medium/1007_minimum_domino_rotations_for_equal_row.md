# minDominoRotations Solution: Intuition

This solution determines the minimum number of rotations needed to make all the dominoes have the same number on either the top or bottom, using the fewest rotations possible. The goal is to make all dominoes show the same value on either the top or bottom by rotating the least number of dominoes.

## Step-by-Step Explanation:

1. **Initialization**:
   - The function `minDominoRotations` starts by setting an initial result (`res`) to `-1`, which will store the minimum number of rotations.
   - We then iterate over all possible values (`val`) from `1` to `6`, since each domino has numbers between 1 and 6 on its sides.
   
   ```cpp
   int res = -1;
   for (int val = 1; val <= 6; ++val) {
       auto curr = helper(tops, bottoms, val);
       if (curr != -1 && (res == -1 || res > curr))
           res = curr;
   }
   ```

2. **Helper Function (Checking Valid Rotations)**:
   - The helper function `helper` takes the top and bottom vectors of the dominoes and the target value (`val`).
   - It initializes two counters (`res_top` and `res_bottom`) to count how many dominoes need to be rotated to have `val` on the top or bottom.
   - The function iterates over the indices of the `tops` and `bottoms` arrays:
     - If neither the top nor the bottom matches `val`, it returns `-1`, meaning it's impossible to achieve the target value on all dominoes.
     - If only the top does not match `val`, it increments `res_top` (indicating a required rotation to the bottom).
     - If only the bottom does not match `val`, it increments `res_bottom` (indicating a required rotation to the top).
     
   ```cpp
   int res_top = 0;
   int res_bottom = 0;
   for (size_t i = 0; i < tops.size(); ++i) {
       if (tops[i] != val && bottoms[i] != val)
           return -1;
       else if (tops[i] != val)
           ++res_top;
       else if (bottoms[i] != val)
           ++res_bottom;
   }
   ```

3. **Return the Minimum Rotations**:
   - The function returns the minimum of `res_top` and `res_bottom`, which gives the least number of rotations required to make all the dominoes show `val` on either side.
   - If no valid rotation is found, `res` remains `-1`, indicating that it's impossible to achieve the target value.

   ```cpp
   return std::min(res_top, res_bottom);
   ```

4. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)**, where `n` is the number of dominoes, because we check all `n` dominoes for each value from 1 to 6. This results in a total of 6 iterations over `n` elements, making the overall complexity **O(6n)**, which simplifies to **O(n)**.
   - **Space Complexity**: The space complexity is **O(1)**, as the solution uses a constant amount of extra space (only a few variables for counting rotations).

## Key Insights:

- **Iterating Over Possible Values**:
  - By iterating over all possible values from 1 to 6, we ensure that we account for all potential target numbers that might appear on either the top or bottom of the dominoes.

- **Counting Rotations**:
  - The helper function efficiently counts the number of rotations required for each possible value (`val`). It avoids unnecessary recomputations by stopping early when an invalid configuration is encountered.

- **Greedy Approach**:
  - The solution employs a greedy approach by trying to match the target value and minimizing the number of rotations required, returning the least value found across all possibilities.

## Final Thoughts:

This solution efficiently finds the minimum number of domino rotations in **O(n)** time and **O(1)** space by checking each possible value and counting the necessary rotations. It provides a simple and effective approach to solving the problem while ensuring correctness through early termination when an invalid configuration is encountered.
