# moveZeroes Solution: Intuition

This solution is designed to move all zeros in a given list of integers to the end while maintaining the relative order of the non-zero elements. The algorithm efficiently does this in-place using a **sliding window** technique where one part of the array holds the non-zero elements and the other part holds the zeros that will eventually be moved to the end.

## Step-by-Step Explanation:

1. **Find the First Zero**:
   - The algorithm starts by using `std::find` to locate the first occurrence of a zero in the list. This marks the starting point for the sliding window, where the left side of the window holds non-zero elements and the right side holds zeros.

   ```cpp
   auto first = std::find(nums.begin(), nums.end(), 0);
   ```

2. **Iterate Through the List**:
   - After locating the first zero, we iterate through the list starting from the first zero using the `j` pointer.
   - For each element `j` that is **not zero**, we swap it with the element at `first`. This effectively slides non-zero elements to the left side of the window, gradually pushing zeros to the right side.

   ```cpp
   if(first != nums.end())
       for (auto j = first; ++j != nums.end();) {
           if (!(*j == 0)) 
               std::iter_swap(first++, j);
       }
   ```

   - After each swap, the `first` pointer is incremented, tracking the next zero to be replaced.

3. **Return the Modified List**:
   - Once the iteration and swapping are complete, the list will have all the zeros moved to the end, and the modified list is returned.

   ```cpp
   return nums;
   ```

4. **Overloading the Stream Insertion Operator**:
   - For convenience, the stream insertion operator (`<<`) is overloaded to allow easy printing of `std::vector<int>` objects.

   ```cpp
   std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
       out << "{";
       for (char sep[]{0, ' ', 0}; const auto& el : v)
           out << sep << el, sep[0] = ',';
       out << "}";
       return out;
   }
   ```

5. **Time and Space Complexity**:
   - **Time Complexity**: The time complexity is **O(n)**, where `n` is the length of the `nums` vector. The algorithm iterates through the list once, performing constant time operations for each element.
   - **Space Complexity**: The space complexity is **O(1)**, since the solution modifies the list in-place and only uses a few additional variables (pointers).

## Key Insights:

- **In-Place Modifications**:
  - The solution performs the task in-place, meaning no additional space is required beyond the input list. This is achieved by swapping non-zero elements to the front of the list and gradually moving zeros to the back.
  
- **Sliding Window Technique**:
  - The sliding window technique is used to keep track of the position of zeros and non-zero elements. The window slides from left to right, and non-zero elements are moved forward while zeros are pushed to the end.

- **Edge Cases**:
  - The solution handles edge cases, such as:
    - A list with no zeros (e.g., `{1}`), where the list remains unchanged.
    - A list with only one zero (e.g., `{0}`), where the zero is moved to the end.
    - A list with multiple zeros (e.g., `{0, 0, 1, 2, 3}`), which correctly moves all zeros to the end while maintaining the order of non-zero elements.

## Final Thoughts:

This `moveZeroes` solution efficiently moves all zeros in a list to the end in **O(n)** time and **O(1)** space. By leveraging the sliding window technique, the algorithm minimizes memory usage while maintaining the order of non-zero elements. This approach provides an optimal solution for the problem.
