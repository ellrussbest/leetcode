# maxProfit Solution: Intuition

This solution aims to find the maximum profit that can be made from buying and selling a stock, given an array of stock prices where each element represents the price of the stock on a given day. The solution uses a sliding window approach to track the minimum price encountered so far and calculates the potential profit for each subsequent day, updating the maximum profit as needed.

## Step-by-Step Explanation:

1. **Initialization**:
   - We start by initializing `max_profit` to 0, which will store the maximum profit encountered during the iteration.
   - The `i` and `j` iterators are used to track the current buying day and the current selling day, respectively.

   ```cpp
   auto max_profit = 0;
   ```

2. **Iterate Through Prices**:
   - We use a loop to iterate through the `prices` vector. The variable `i` represents the potential buying day, and `j` represents the potential selling day.
   - If the price on day `j` is higher than the price on day `i`, calculate the profit (`profit = *j - *i`).
     - If this profit is greater than the current `max_profit`, update `max_profit`.
     - If the profit is negative (i.e., the price on day `j` is lower than on day `i`), update `i` to `j`, as a lower price has been found and could be a better buying opportunity.

   ```cpp
   for (auto i = prices.begin(), j = i; ++j != prices.end();) {
       if (auto profit = *j - *i; profit < 0)
           i = j;
       else
           max_profit = std::max(max_profit, profit);
   }
   ```

3. **Return the Maximum Profit**:
   - After iterating through the list of prices, return `max_profit` which holds the highest profit achievable from any valid buy-sell pair in the given prices.

   ```cpp
   return max_profit;
   ```

4. **Time and Space Complexity**:
   - **Time Complexity**: The time complexity is **O(n)**, where `n` is the length of the `prices` array. We only iterate through the array once, performing constant time operations for each element.
   - **Space Complexity**: The space complexity is **O(1)** because we are only using a few variables (`max_profit`, `i`, `j`) to track the necessary information, and no additional data structures are used.

## Key Insights:

- **Greedy Approach**:
  - The solution uses a greedy approach by always looking for the next opportunity to make a profit, while ensuring that the buy day (`i`) is always before the sell day (`j`).
  - By updating `i` when a lower price is found, the algorithm effectively tracks the minimum price seen so far, allowing it to calculate the best possible profit as we move through the list.

- **Efficient Calculation**:
  - The solution efficiently computes the maximum profit in a single pass through the list. At each step, it calculates the potential profit and updates the maximum profit only if it exceeds the previous maximum.

- **Edge Cases**:
  - The solution handles edge cases like a descending price array (e.g., `{7, 6, 4, 3, 1}`), where the result will be 0 since no profit can be made.
  - It also handles arrays where the price steadily increases, returning the maximum possible profit.

## Final Thoughts:

This `maxProfit` solution efficiently computes the maximum profit from a series of stock prices using a greedy approach with **O(n)** time complexity and **O(1)** space complexity. By tracking the minimum price and calculating the profit dynamically, it ensures that we find the optimal buy-sell pair for maximum profit.