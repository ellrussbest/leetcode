# Majority Element Solution: Intuition

This solution finds the majority element in an array of integers using the **Boyer-Moore Voting Algorithm**. The majority element is the element that appears more than ⌊ n / 2 ⌋ times, where `n` is the size of the list. This approach allows us to identify the majority element in linear time and constant space.

## Step-by-Step Explanation:

1. **Initialization**:
   - We initialize two variables:
     - `candidate`: This will hold the current candidate for the majority element. It is initially set to `0` (though any value from the array can be used).
     - `count`: This keeps track of the number of times the `candidate` has been "voted for." It starts at `0`.

   ```cpp
   int candidate = 0;
   int count = 0;
   ```

2. **Iterate Through the List**:
   - We loop through the list:
     - If `count` is `0`, it means we have no current candidate, so we set `candidate` to the current element (`*i`).
     - If the current element `*i` is equal to the `candidate`, we increment `count` (we're "voting" for this candidate).
     - If the current element `*i` is different from the `candidate`, we decrement `count` (we're "eliminating" this candidate).
   
   The process is essentially "cancelling out" votes, with the idea that the majority element will remain as the candidate by the end.

   ```cpp
   for (auto i = nums.begin(); i != nums.end(); ++i) {
       if (count == 0)
           candidate = *i;
                
       if (*i == candidate)
           ++count;
       else
           --count;
   }
   ```

3. **Return the Majority Element**:
   - After the loop finishes, the `candidate` variable holds the majority element, which is then returned.

   ```cpp
   return candidate;
   ```

4. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity is **O(n)** because we only iterate through the list once.
   - **Space Complexity**: The space complexity is **O(1)** because we only use a constant amount of extra space (`candidate` and `count`).

## Key Insights:

- **Boyer-Moore Voting Algorithm**:
  - The key idea behind this algorithm is that the majority element, if it exists, will survive the elimination process. When the count reaches 0, the algorithm starts with a new candidate. The majority element will have enough "votes" to remain as the final candidate.
  
- **Efficiency**:
  - The algorithm is highly efficient, running in **O(n)** time and requiring only **O(1)** space. This makes it optimal for large inputs where space efficiency is important.

- **Correctness**:
  - This algorithm guarantees the majority element will be returned if a majority exists, but it assumes that the input list always has a majority element. If no majority element exists, this approach may return an incorrect result.

## Final Thoughts:

This solution efficiently finds the majority element in a list by using the Boyer-Moore Voting Algorithm. It achieves **O(n)** time complexity and **O(1)** space complexity, making it ideal for large datasets. The algorithm's simplicity and efficiency make it a robust choice for solving the majority element problem, provided the input always contains a majority.
