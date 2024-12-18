# Longest Increasing Subsequence: Problem Explanation and Solution

This solution finds the length of the longest increasing subsequence (LIS) in a given array of integers. The approach uses binary search to efficiently update a dynamic list that helps track potential subsequences.

## Problem Overview:

### Input:
- A vector `nums` containing integers, where the goal is to find the length of the longest strictly increasing subsequence in the array.

### Output:
- The length of the longest increasing subsequence.

For example:
- **Input**: `[10,9,2,5,3,7,101,18]`
- **Output**: `4` (The longest increasing subsequence is `[2, 3, 7, 18]`)

- **Input**: `[0,1,0,3,2,3]`
- **Output**: `4` (The longest increasing subsequence is `[0, 1, 2, 3]`)

- **Input**: `[7,7,7,7,7,7,7]`
- **Output**: `1` (The longest increasing subsequence is `[7]`)

---

## Step-by-Step Explanation:

### 1. **Initialize the Vector `v`**:
   We maintain a vector `v` where each element represents the smallest possible tail value for all increasing subsequences of a given length.

   ```cpp
   std::vector<int> v;
   ```

   - The length of the vector `v` will give the length of the longest increasing subsequence.
   
### 2. **Iterate Over Each Number in `nums`**:
   For each number in the input vector `nums`, we perform a binary search using `std::lower_bound` to determine the position where this number could replace an element in `v`.

   ```cpp
   auto it = std::lower_bound(v.begin(), v.end(), num);
   ```

   - `std::lower_bound` returns an iterator pointing to the first element in `v` that is greater than or equal to `num`. This ensures that the subsequence remains increasing.
   
### 3. **Update the Vector `v`**:
   - If `it` points to the end of the vector (`v.end()`), it means `num` is greater than any element in `v`, so we append it to `v` as a new element.
   
   ```cpp
   if(it == v.end())
       v.emplace_back(num);
   ```

   - If `it` does not point to the end, it means there is an element in `v` that can be replaced by `num` to maintain the smallest possible tail value for the subsequence. We replace the element at `it` with `num`.
   
   ```cpp
   else
       *it = num;
   ```

### 4. **Return the Length of the Longest Increasing Subsequence**:
   The size of vector `v` at the end of the loop will give the length of the longest increasing subsequence.

   ```cpp
   return static_cast<int>(v.size());
   ```

---

### 5. **Edge Case Handling**:
   - **Empty Input**: If the input vector is empty, the algorithm will return `0` as there is no subsequence.
   - **All Equal Elements**: If all elements in the input are the same, the longest increasing subsequence will have length `1`.
   
   For example:
   - **Input**: `[7,7,7,7,7,7,7]`
   - **Output**: `1`

---

## Time and Space Complexity:

- **Time Complexity**:  
  The algorithm runs in **O(n log n)** time, where `n` is the length of the input vector `nums`. For each element, we perform a binary search (`O(log n)`) in the vector `v`, and this is done for every element in `nums`.

- **Space Complexity**:  
  The space complexity is **O(n)** due to the vector `v`, which stores the smallest possible tail values for subsequences of various lengths.

---

## Final Thoughts:

This solution efficiently finds the length of the longest increasing subsequence using binary search combined with dynamic programming. The approach runs in **O(n log n)** time, making it suitable for large inputs. By maintaining a dynamic vector of subsequences' smallest tails, the solution ensures that it can track potential subsequences efficiently.
