# Sequential Digits Solution: Intuition

This solution generates all the numbers between `low` and `high` that consist of sequential digits (i.e., digits that increase by 1, such as 123, 234, 345, etc.). It efficiently constructs these numbers by leveraging digit manipulation techniques.

## Step-by-Step Explanation:

### 1. **Initialization**:
   - **Digits Vector**: We initialize a vector `digits` that contains the digits from `1` to `9`, which we use to generate the sequential digits.
   - **Result Vector**: We create a vector `res` to store the sequential digits that fall within the specified range `[low, high]`.
   - **Base and Divisor**: The `base` is computed by calculating the logarithm of `low` to determine the number of digits in `low`. We then compute the `divisor` as `10` raised to the power of `base`, which helps with digit extraction.

   ```cpp
   std::vector digits{1, 2, 3, 4, 5, 6, 7, 8, 9};
   std::vector<int> res;

   int base = static_cast<int>(std::log10(low));
   int divisor = static_cast<int>(std::pow(10, base));
   ```

### 2. **Pointer Initialization and First Number Construction**:
   - **First Pointer**: The `first` iterator points to the first relevant digit that could form a valid sequential number. It is set by advancing from the start of the `digits` vector, using the formula `static_cast<int>(low / divisor)` to find the starting digit.
   - **Last Pointer**: Initially, the `last` pointer is set to the end of the `digits` vector (`digits.end()`), which marks the end of the range of valid digits.
   - **Current Value (`curr`)**: `curr` is initialized to `0` to store the currently constructed sequential number.

   ```cpp
   auto first = --std::next(digits.begin(), static_cast<int>(low / divisor)));
   auto last = digits.end();
   auto curr = 0;
   ```

   ### 3. **First Sequential Number Construction**:
   - We check if the sequence of digits starting from `first` and using the current base (number of digits for the sequential number) can form a valid number less than or equal to `high`.
   - The `last` pointer is adjusted to mark the correct range of digits, and the first number is constructed using the `construct_number` function.

   ```cpp
   if(std::distance(digits.begin(), first) + base < 9) {
       last = ++std::next(first, base);
       curr = construct_number(first, last);
   }
   ```

### 4. **Constructing and Iterating Through Sequential Numbers**:
   The main loop starts by checking if `curr` is within the given range `[low, high]`. If it is, the current number is added to the result vector `res`. The loop continues until the current number exceeds `high` or until all valid sequential numbers are exhausted.

   ```cpp
   while (curr <= high) {
       if(curr >= low) 
           res.emplace_back(curr);
       // Check base limit
   }
   ```

   ### 5. **Updating `first`, `last`, and `curr` for New Base (When Needed)**:
   If we reach the end of the current sequence (i.e., the `last` iterator reaches the end of the `digits` vector), it means the current sequence cannot be extended further. In such cases:
   - The base is incremented to construct a larger sequential number (increasing the number of digits).
   - The divisor is adjusted accordingly (`divisor = 10^base`).
   - `first` is reset to the start of the `digits` vector, and `last` is adjusted to point to the appropriate range for the new number of digits.

   ```cpp
   if (last == digits.end()) {
       ++base;
       divisor = static_cast<int>(std::pow(10, base));
       first = digits.begin();
       last = ++std::next(first, base);
       curr = construct_number(first, last);
   }
   ```

### 6. **Constructing New Sequential Number in the Else Part**:
   If `last` has not reached the end of the `digits` vector, we continue constructing the number by modifying the current `curr`:
   - The most significant digit (`msv`) is calculated by removing the portion of `curr` that corresponds to the current base.
   - We then add the next digit from `last` to form the next sequential number.

   ```cpp
   int msv = static_cast<int>(curr / divisor) * divisor;
   curr -= msv;
   curr = curr * 10 + *last++;
   ```

### 7. **Helper Function - `construct_number`**:
   The `construct_number` function takes two iterators (`first` and `last`) and constructs an integer by iterating over the digits in the range from `first` to `last`. It multiplies the current result by 10 and adds each digit, effectively building the number step-by-step.

   ```cpp
   template <typename ForwardIt>
   int construct_number(ForwardIt first, ForwardIt last) {
       int res = 0;
       while (first != last) 
           res = res * 10 + *first++;
       return res;
   }
   ```

### 8. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)** where `n` is the number of sequential digit numbers in the range `[low, high]`. The `construct_number` function is called for each valid sequential number, and the loop iterates through all possible numbers.
   - **Space Complexity**: The space complexity is **O(k)** where `k` is the number of valid sequential numbers in the range `[low, high]`. This is the space used by the result vector `res`.

## Key Insights:

- **Efficient Generation of Sequential Numbers**:
  - The algorithm leverages the `digits` vector and iterators to dynamically generate each valid sequential number in the range without brute-forcing all possible numbers. This significantly reduces unnecessary computations.
  
- **Base Adjustments for Larger Numbers**:
  - As we generate sequential numbers, the base (number of digits) is dynamically adjusted, allowing the generation of numbers of varying lengths. This dynamic adjustment ensures we never generate invalid numbers.

- **Iterative Number Construction**:
  - The number construction is done iteratively by manipulating the `first` and `last` pointers and adjusting `curr` to build the next number in sequence. This efficient approach ensures that no unnecessary computations are made.

## Final Thoughts:

This solution efficiently generates all sequential digit numbers within a specified range `[low, high]` in **O(n)** time and **O(k)** space. It avoids brute-force enumeration of all numbers in the range and instead constructs only those numbers that meet the criteria for sequential digits. The use of dynamic iterators (`first` and `last`) and base adjustments ensures that the solution is both efficient and easy to understand.