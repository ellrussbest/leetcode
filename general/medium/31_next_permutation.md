# `nextPermutation` Solution: Intuition

This solution finds the next lexicographical permutation of a given sequence of numbers. If the sequence is the largest permutation (i.e., in descending order), it rearranges the sequence into the smallest permutation (ascending order). The solution leverages the built-in `std::next_permutation` algorithm for simplicity and efficiency.

## Step-by-Step Explanation:

1. **Calling `std::next_permutation`**:
   - The `std::next_permutation` function from the C++ Standard Library is designed to rearrange the elements in a given range to the next lexicographically greater permutation. 
   - If the sequence is already the largest permutation, it rearranges it into the smallest permutation.
   
   ```cpp
   std::next_permutation(nums.begin(), nums.end());
   ```

2. **Return Result**:
   - After modifying the sequence, the updated vector is returned.
   
   ```cpp
   return nums;
   ```

3. **Output Formatting**:
   - To output the vector in a readable format, we define an overloaded `<<` operator for printing vectors. This operator ensures that the vector elements are printed enclosed in curly braces and separated by commas.

   ```cpp
   std::ostream& operator<<(std::ostream& out, const std::vector<int>& v) {
       out << "{";
       for (char sep[]{0, ' ', 0}; const auto& el : v)
           out << sep << el, sep[0] = ',';
       out << "}";

       return out;
   }
   ```

4. **Main Function**:
   - In the `main` function, the `nextPermutation` method is called with different test cases. The results are printed using the overloaded stream insertion operator.
   
   ```cpp
   std::cout << Solution{}.nextPermutation({1, 2, 3}) << "\n";
   std::cout << Solution{}.nextPermutation({3, 2, 1}) << "\n";
   std::cout << Solution{}.nextPermutation({1, 1, 5}) << "\n";
   ```

5. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)** because `std::next_permutation` processes each element of the vector at most once, where `n` is the number of elements in the vector.
   - **Space Complexity**: The space complexity is **O(1)** because the solution modifies the vector in place without using extra space except for a few temporary variables.

## Key Insights:

- **Built-In Algorithm**:
  - The solution leverages the efficient `std::next_permutation` function, which simplifies the task of finding the next lexicographical permutation.
  
- **Handling Largest Permutation**:
  - The solution correctly handles the case when the input is the largest permutation by wrapping around to the smallest permutation (ascending order).

- **Efficient Output**:
  - The overloaded `<<` operator for `std::vector` ensures that the output format is clean and easy to read.

## Final Thoughts:

The `nextPermutation` solution efficiently computes the next lexicographical permutation of a sequence in **O(n)** time and **O(1)** space, using the built-in `std::next_permutation` algorithm. The solution is optimal, concise, and leverages standard library functionality for simplicity.