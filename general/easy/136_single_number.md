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

## singleNumber_bruteforce Solution: Intuition

This solution efficiently solves the problem of finding the number that appears only once in a list, while all other numbers appear in pairs. It uses an `std::unordered_set` to track numbers as we iterate through the list, ensuring we handle duplicate numbers correctly by adding or removing them based on whether we've seen them before.

## Step-by-Step Explanation:

1. **Initialize the Unordered Set**:
   We start by initializing an empty `std::unordered_set<int>` called `set`. This set will be used to track numbers we encounter as we iterate through the list. The unordered set allows for efficient lookup, insertion, and deletion.

   ```cpp
   std::unordered_set<int> set;
   ```

   The unordered set is a good choice here because it provides average constant time complexity for insertions and lookups.

2. **Iterate Through the Input Vector**:
   We then iterate through each number in the input vector `nums` using a range-based `for` loop. For each number `num`, we perform the following steps:

   ```cpp
   for (const auto& num : nums) {
       auto [it, success] = set.emplace(num);
       if (!success) set.erase(it);
   }
   ```

3. **Find and Handle Existing or New Numbers**:
   For each number, we use the `emplace` method to attempt to insert it into the set. The `emplace` method returns a pair of values: an iterator (`it`) and a boolean (`success`).
   - **When `success` is `false`**: It means the number is already in the set, so we remove it to cancel out the pair.
   - **When `success` is `true`**: It means the number is not in the set, so we insert it.

   This method ensures that only the number that appears once will remain in the set by the end of the iteration.

4. **Return the Remaining Element**:
   After iterating through all the numbers, the set will contain only one element—the number that appears an odd number of times (once). Since the set only holds this number, we return it by dereferencing `set.begin()`, which points to the first (and only) element in the set.

   ```cpp
   return *set.begin();
   ```

---

## Key Insights:

- **Efficient Operations**:
  - The `unordered_set` provides efficient **average O(1)** time complexity for insertion, lookup, and removal, making this method faster for large inputs compared to solutions that use data structures with higher time complexities (like `std::set`).

- **Time and Space Complexity**:
  - **Time Complexity**: The time complexity is **O(n)** because we iterate through the list once, with average O(1) complexity for each operation on the unordered set.
  - **Space Complexity**: The space complexity is **O(n)** because the set may store up to `n` elements in the worst case.

---

## Example Walkthrough:

Consider the input vector `nums = [4, 1, 2, 1, 2]`:

1. Initialize `set` as an empty unordered set.
2. Iterate through the list:
   - `set.emplace(4)` → `set = {4}`.
   - `set.emplace(1)` → `set = {4, 1}`.
   - `set.emplace(2)` → `set = {4, 1, 2}`.
   - `set.emplace(1)` → `set = {4, 2}` (1 is removed).
   - `set.emplace(2)` → `set = {4}` (2 is removed).
   
   After all numbers have been processed, `set = {4}`.

3. Return `4`.

---

## Key Advantages:

- **Optimal for Large Inputs**: This solution is optimal in terms of time complexity, running in **O(n)** time, but requires more space (**O(n)**) compared to the XOR approach.
- **Simplicity**: The use of an unordered set ensures that the solution remains simple and easy to understand while handling duplicates efficiently.

---

## Final Thoughts:

This `singleNumber_bruteforce` solution efficiently finds the unique element in an array where every other element appears twice. By leveraging the `unordered_set`, we can easily track elements and remove pairs as we encounter them. While this solution is not as space-efficient as the XOR approach, it offers good performance in terms of time complexity.
