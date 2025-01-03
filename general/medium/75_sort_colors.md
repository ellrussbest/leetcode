# Sort Colors Solution: Intuition

This solution sorts an array of integers, which represents a set of colors coded as `0`, `1`, and `2`. The goal is to sort the array such that all `0`s appear first, followed by all `1`s, and then all `2`s. The solution utilizes the QuickSort algorithm, which is tailored to sort the array by partitioning it based on a pivot.

## Step-by-Step Explanation:

1. **Main Function - `sortColors`**:
   - The `sortColors` function is the entry point. It takes a vector `nums` of integers (which represent colors) as an rvalue reference (i.e., `&&`).
   - The function then calls the private `quick_sort` function to perform the sorting.
   
   ```cpp
   std::vector<int> sortColors(std::vector<int>&& nums) {
       quick_sort(nums.begin(), nums.end());
       return nums;
   }
   ```

2. **QuickSort Function - `quick_sort`**:
   - **Base Case**: If the range of elements to sort is empty or contains a single element (`first == last`), the function simply returns without doing anything.
   
     ```cpp
     if(first == last)
         return;
     ```

   - **Pivot Selection**: The pivot element is selected as the middle element of the current range. This helps in balancing the partitioning, reducing the likelihood of worst-case performance.

     ```cpp
     const auto pivot = *std::next(first, std::distance(first, last) / 2);
     ```

   - **Partitioning**: 
     - The array is partitioned into three parts using `std::partition`. 
     - The first partition (`middle1`) contains all elements smaller than the pivot.
     - The second partition (`middle2`) contains all elements greater than or equal to the pivot.
     - The third part naturally arises as elements equal to the pivot are grouped in the middle.

     ```cpp
     auto middle1 = std::partition(first, last, [&pivot](auto& el){
         return el < pivot;
     });
     auto middle2 = std::partition(middle1, last, [&pivot](auto& el) {
         return !(pivot < el);
     });
     ```

   - **Recursive Sorting**:
     - The function then recursively sorts the two partitions: the part before `middle1` and the part after `middle2`.

     ```cpp
     quick_sort(first, middle1);
     quick_sort(middle2, last);
     ```

3. **Overloaded Output Operator for Display**:
   - The `operator<<` for `std::ostream` is overloaded to allow printing the vector in a human-readable format. It outputs the vector as `{0, 1, 2, ...}`.

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
   - The `main` function demonstrates the use of the `sortColors` method by testing it on two example input arrays:
     - Sorting the array `{2, 0, 2, 1, 1, 0}`.
     - Sorting the array `{0, 1, 2}`.

   ```cpp
   std::cout << Solution{}.sortColors({2, 0, 2, 1, 1, 0}) << "\n";
   std::cout << Solution{}.sortColors({0, 1, 2}) << "\n";
   ```

5. **Space and Time Complexity**:
   - **Time Complexity**: The time complexity of QuickSort is **O(n log n)** on average, where `n` is the number of elements in the vector. In the worst case, the time complexity can be **O(n^2)** if the pivot selection is poor (e.g., always choosing the smallest or largest element).
   - **Space Complexity**: The space complexity is **O(log n)** because the recursive stack depth is proportional to the logarithm of the number of elements being sorted.

## Key Insights:

- **QuickSort**: 
  - QuickSort is a divide-and-conquer sorting algorithm. It works by choosing a pivot element, partitioning the array into two smaller subarrays (those less than the pivot and those greater than or equal to it), and then recursively sorting each subarray. 
  - In this solution, the pivot is chosen as the middle element of the current range, which helps to avoid the worst-case scenario (e.g., if the array is already sorted or reverse-sorted).
  
- **Partitioning Logic**:
  - The solution makes use of `std::partition` to divide the array into three parts: elements smaller than the pivot, elements equal to the pivot, and elements greater than the pivot. This partitioning logic is key for sorting the colors correctly, as the only possible values are `0`, `1`, and `2`.

- **Efficient Recursion**:
  - The recursive calls break down the problem into progressively smaller subarrays, making the sorting process efficient and scalable.

## Final Thoughts:

This `sortColors` solution efficiently sorts a vector of integers representing colors in **O(n log n)** time on average, utilizing QuickSort with three-way partitioning. The use of `std::partition` helps simplify the sorting logic and ensures that the algorithm performs well even with arrays of mixed color codes. The space complexity is minimized due to the in-place nature of QuickSort, making this solution both time-efficient and space-efficient for this problem.
