# Lemonade Change Solution: Intuition

This solution determines if it's possible to give correct change to each customer in a line, based on the bills they provide. The process involves tracking how many 5 and 10 dollar bills are available, and using them to give change for larger bills (like 20 dollars). 

## Step-by-Step Explanation:

1. **Initialization**:
   - We initialize two variables `fives` and `tens` to keep track of the number of 5-dollar and 10-dollar bills the cashier has.
   - Initially, both are set to 0.

   ```cpp
   int fives = 0;
   int tens = 0;
   ```

2. **Processing Each Customer's Bill**:
   - We loop through each bill in the `bills` vector:
     - If the bill is 5 dollars, we increment the count of `fives`.
     - If the bill is 10 dollars, we check if there is at least one 5-dollar bill to provide change. If so, we decrement `fives` and increment `tens`. If not, we return `false` because we can't give the correct change.
     - If the bill is 20 dollars, we try to give change using one 10-dollar bill and one 5-dollar bill if possible. If not, we check if we have at least three 5-dollar bills to give the change. If neither condition is met, we return `false` because we can't give the correct change.

   ```cpp
   for (const auto& bill : bills) {
       if (bill == 5)
           ++fives;
       else if (bill == 10) {
           if (fives <= 0)
               return false;
           ++tens, --fives;
       } else {
           if (tens > 0 && fives > 0)
               --tens, --fives;
           else if (fives >= 3)
               fives -= 3;
           else
               return false;
       }
   }
   ```

3. **Return Result**:
   - After processing all the bills, if we haven’t encountered a situation where it's impossible to give change, we return `true`.

   ```cpp
   return true;
   ```

4. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)**, where `n` is the number of customers (or the length of the `bills` vector). We process each bill once and perform constant-time operations.
   - **Space Complexity**: The space complexity is **O(1)** because we only use a constant amount of extra space (two integer variables `fives` and `tens`).

## Key Insights:

- **Greedy Approach**:
  - The solution uses a greedy approach, always trying to give change with the largest possible bills first. This ensures that we use the fewest possible bills and leave more flexibility for future customers.
  
- **Efficient Tracking**:
  - By only tracking the number of 5-dollar and 10-dollar bills, the solution efficiently determines whether it’s possible to give correct change.

- **Edge Cases**:
  - If a 10-dollar or 20-dollar bill is encountered when there aren’t enough 5-dollar bills for change, the function immediately returns `false`.

## Final Thoughts:

This solution solves the lemonade change problem in **O(n)** time with **O(1)** space, ensuring that the cashier can efficiently handle each customer’s bill and provide change when possible. If you have any questions or need further clarification, feel free to ask!