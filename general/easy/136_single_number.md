# singleNumber Solution: Intuition

This solution solves the problem of finding the number that appears only once in a list, where all other numbers appear in pairs. The solution uses the XOR bitwise operator to efficiently find the unique number in linear time with constant space.

## Step-by-Step Explanation:

1. **Initialization**:
   We start by initializing a variable `res` to 0. This variable will hold the result of the XOR operations as we iterate through the list of numbers.

   ```cpp
   int res{};
   ```

   The initial value of `res` is `0` because XORing a number with `0` leaves the number unchanged, which is key to the logic of this solution.

2. **Iterate Through the Input Vector**:
   We iterate through the input vector `nums`, applying the XOR operator on `res` and each number `num` in the list.

   ```cpp
   for (const auto& num : nums) res = res ^ num;
   ```

   The key property of XOR is that it satisfies the following:

   - **Self-cancellation**: For any integer `a`, `a ^ a = 0`. This means that if we XOR a number with itself, it cancels out to zero.
   - **Commutativity and Associativity**: The order in which we XOR the numbers does not matter. We can XOR the numbers in any order and the result will be the same.

   So, as we iterate through the list:
   - Each number that appears twice will cancel itself out because `a ^ a = 0`.
   - The number that appears only once will be left behind because it doesn't have a matching pair to cancel out.

3. **Return the Result**:
   After iterating through all the numbers, the only remaining value in `res` is the number that appeared an odd number of times (in this case, exactly once).

   ```cpp
   return res;
   ```

   At this point, `res` contains the unique number, as all paired numbers have canceled each other out.

## Key Insights:

- **XOR Property**:
  - The XOR operator (`^`) has the unique property that when applied to the same number twice, it results in zero. This is critical for efficiently removing the paired numbers from the calculation.
  - XOR is **commutative** and **associative**, meaning that the order of operations doesn’t matter. This allows us to iterate through the array and XOR each number with `res` in any order.

- **Efficient Time and Space Complexity**:
  - **Time Complexity**: The time complexity is **O(n)** because we only need to iterate through the list once, where `n` is the number of elements in the list.
  - **Space Complexity**: The space complexity is **O(1)** because we are using only a single integer variable (`res`) to store the result, regardless of the size of the input array.

- **Constant Space Solution**:
  - This approach uses **constant space** since we do not need any additional data structures like sets or maps. We only store a single integer, `res`, which makes this solution highly space-efficient.

---

## Example Walkthrough:

Consider the input vector `nums = [4, 1, 2, 1, 2]`:

1. Initialize `res = 0`.
2. XOR the numbers one by one:
   - `res = 0 ^ 4 = 4` i.e. `000 ^ 100 = 100`
   - `res = 4 ^ 1 = 5` i.e. `100 ^ 101 = 101`
   - `res = 5 ^ 2 = 7` i.e. `101 ^ 010 = 111`
   - `res = 7 ^ 1 = 6` i.e. `111 ^ 001 = 110`
   - `res = 6 ^ 2 = 4` i.e. `110 ^ 010 = 100`
   
   After all numbers have been processed, `res = 4`, which is the number that appeared only once.

3. Return `res = 4`.

---

## Key Advantages:

- **Optimal for Large Inputs**: This solution is optimal in terms of both time and space. It runs in linear time (`O(n)`) and uses constant space (`O(1)`), making it ideal for large inputs.
- **Simplicity**: The XOR approach is simple, elegant, and avoids the need for extra data structures (like sets or maps), which would require more memory.

---

## Final Thoughts:

This `singleNumber` solution efficiently finds the unique element in an array where every other element appears twice. By leveraging the properties of the XOR operator, we can solve the problem in **O(n)** time and **O(1)** space, making it an optimal solution both in terms of performance and memory usage.


# singleNumber_bruteforce Solution: Intuition

This solution efficiently solves the problem of finding the number that appears only once in a list, while all other numbers appear in pairs. It uses a `std::set` to track numbers as we iterate through the list, ensuring we handle duplicate numbers correctly by adding or removing them based on whether we've seen them before.

## Step-by-Step Explanation:

1. **Initialize the Set**:
   We start by initializing an empty `std::set<int>` called `m_set`. This set will be used to track numbers we encounter as we iterate through the list. The set automatically maintains the numbers in sorted order, which allows us to efficiently check for duplicates.

   ```cpp
   std::set<int> m_set;
   ```

   The set is a good choice here because it ensures that we don't store duplicates and allows efficient operations for insertion and removal.

2. **Iterate Through the Input Vector**:
   We then iterate through each number in the input vector `nums` using a range-based `for` loop. For each number `num`, we perform the following steps:

   ```cpp
   for (const auto& num : nums) {
   ```

3. **Find and Handle Existing or New Numbers**:
   For each number, we use `lower_bound` to check if the number is already in the set. The `lower_bound` function returns an iterator to the first element in the set that is *greater than or equal* to the given number. If the number is not present, `lower_bound` will return an iterator pointing to the end of the set (`m_set.end()`), indicating that the number is not in the set.

   - **When `num` is not found**: If `lower_bound(num)` returns `m_set.end()`, it means `num` is not currently in the set, so we insert it.
   - **When `num` is found**: If `lower_bound(num)` returns an iterator pointing to an existing element equal to `num`, we remove it since we've encountered a pair. 

   ```cpp
   if (auto it = m_set.lower_bound(num); it == m_set.end() || *it > num) {
       m_set.emplace_hint(it, num);  // Insert the number if it's not already in the set
   } else {
       m_set.erase(it);  // Remove the number if it's already in the set (it forms a pair)
   }
   ```

4. **Why `lower_bound` and `emplace_hint`?**:
   - **`lower_bound(num)`** returns an iterator to the first element that is not less than `num`. If `num` is already in the set, this iterator will point to it.
   - If `num` is not found in the set, `lower_bound(num)` will return `m_set.end()`. The end iterator, `m_set.end()`, is valid but *not dereferenceable*, so we have to explicitly check for this case to avoid accessing it.
   - **`emplace_hint(it, num)`** inserts `num` at the position suggested by `it`, which is a more efficient way to insert the number into the set while maintaining its sorted order.

5. **Removing the Number**:
   If the number was already present (i.e., we found an exact match), we use `erase(it)` to remove it from the set. This operation "cancels out" the pair, leaving only numbers that appear an odd number of times (in this case, just the one number that appears only once).

6. **Return the Remaining Element**:
   After iterating through all the numbers, the set will contain only one element—the number that appears an odd number of times (once). Since the set only holds this number, we return it by dereferencing `m_set.begin()`, which points to the first (and only) element in the set.

   ```cpp
   return *m_set.begin();
   ```

## Final Thoughts:

This `singleNumber` solution efficiently finds the number that appears once in a list where all other elements appear in pairs. By leveraging the `std::set`, we maintain simplicity, clarity, and a well-balanced solution that handles duplicates correctly. Although the solution has a time complexity of `O(n log n)` due to set operations, it provides a clean and effective approach for solving the problem.