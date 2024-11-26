# FizzBuzz Solution: Intuition

This solution implements the classic FizzBuzz problem. Given an integer `n`, we generate a sequence of strings where:

- For numbers divisible by 3, we append "Fizz" to the result.
- For numbers divisible by 5, we append "Buzz" to the result.
- For numbers divisible by both 3 and 5, we append "FizzBuzz".
- Otherwise, we append the number itself.

## Step-by-Step Explanation:

1. **Initialize the Result Vector**:
   We begin by creating a `std::vector<std::string>` called `res` that has a size of `n`. This vector will hold our results for each number from 1 to `n`.

   ```cpp
   std::vector<std::string> res(static_cast<size_t>(n));
   ```

   This is done to ensure that we have a pre-allocated vector with the appropriate size for all the results.

2. **Loop Through Each Number**:
   We use a `while` loop to iterate through each number from 1 to `n`. The loop is controlled by a `count` variable that starts at 1 and increments until it reaches `n`.

   ```cpp
   int count = 1;
   while (count <= n) {
       std::string el{};  // Temporary string to store the current result
   ```

3. **Check Divisibility for FizzBuzz Logic**:
   For each number `count`, we initialize an empty string `el`. We then check whether `count` is divisible by 3 or 5, appending the appropriate string to `el`:

   - If `count % 3 == 0`, we append "Fizz".
   - If `count % 5 == 0`, we append "Buzz".

   ```cpp
   if (count % 3 == 0) el += "Fizz";
   if (count % 5 == 0) el += "Buzz";
   ```

4. **Handle the Case Where Neither Fizz Nor Buzz Applies**:
   If neither condition is true (i.e., `el` is still empty), we simply append the number itself to the string. This ensures that numbers which are neither divisible by 3 nor 5 are represented as their string equivalents.

   ```cpp
   if (el.size() == 0) el += std::to_string(count);
   ```

5. **Store the Result**:
   The result is then stored in the vector at the position corresponding to `count - 1`. We use `std::move(el)` to efficiently transfer the string into the vector (avoiding unnecessary copies).

   ```cpp
   *(res.begin() + count - 1) = std::move(el);
   ```

6. **Return the Final Result**:
   Once the loop finishes, the vector `res` containing the full FizzBuzz sequence is returned.

   ```cpp
   return res;
   ```

## Key Insights:

- **Efficient String Concatenation**: 
   We build the result string `el` for each number in a straightforward way by conditionally appending either "Fizz", "Buzz", or the number itself. This avoids multiple checks in one go (e.g., checking for divisibility by both 3 and 5 at once).
   
- **Pre-allocation of Vector**: 
   The result vector is initialized with a size equal to `n` upfront, which helps avoid resizing during the loop and improves performance.

- **Move Semantics**:
   Using `std::move(el)` to assign the string to the vector ensures efficient transfer of the string, as it avoids unnecessary copying.