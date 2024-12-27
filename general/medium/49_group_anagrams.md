# Group Anagrams: Problem Explanation and Solution

This solution groups anagrams from a given list of strings. Two strings are considered anagrams if they can be rearranged to form each other. The algorithm leverages a **hash map** (unordered_map) to group strings that are anagrams of each other.

## Problem Overview:

### Input:
A vector of strings `strs`, where each string can be any non-empty word, and we need to group those that are anagrams of each other.

### Output:
A vector of vectors, where each inner vector contains all the anagrams of a particular group.

For example:
- **Input**: `{"eat", "tea", "tan", "ate", "nat", "bat"}`
- **Output**: `{{"eat", "tea", "ate"}, {"tan", "nat"}, {"bat"}}`

- **Input**: `{"a"}`
- **Output**: `{{"a"}}`

- **Input**: `{"", ""}`
- **Output**: `{{""}, {""}}`

---

## Step-by-Step Explanation:

### 1. **Edge Case Handling**:
   If the input vector `strs` is empty, we immediately return a vector containing an empty string inside another vector as a special case:

   ```cpp
   if (strs.empty()) return {{" "}};
   ```

### 2. **Setup the Data Structures**:
   - We use a `std::unordered_map<std::string, std::vector<std::string>>` to store groups of anagrams. The **key** of the map is a sorted version of each string (since anagrams, when sorted, produce the same string), and the **value** is a vector that stores all the strings that are anagrams of that key.
   - We initialize an empty vector `res` to store the final groups of anagrams.

   ```cpp
   std::vector<std::vector<std::string>> res;
   std::unordered_map<std::string, std::vector<std::string>> m_map;
   ```

### 3. **Iterate Through the Input List**:
   We loop over each string `str` in the input vector `strs`. For each string:
   - We **sort** the string to generate the key for the hash map.
   - We attempt to insert the sorted string as a key in the hash map. If the key already exists, the string is added to the corresponding vector of anagrams.

   ```cpp
   for (size_t i = 0; i < strs.size(); ++i) {
       auto key = strs[i];          // Make a copy of the string
       std::sort(key.begin(), key.end());  // Sort the string to use as the key
       auto [it, success] = m_map.try_emplace(key, std::vector<std::string>{strs[i]});
       if (!success) 
         it->second.emplace_back(strs[i]);
   }
   ```

   - `std::sort(key.begin(), key.end())`: This ensures that all anagrams of a given string result in the same sorted string, making them easy to group.
   - `m_map.try_emplace(key, ...)`: This function tries to insert the string into the vector corresponding to the sorted key. If the key already exists, it simply appends the string to the vector.

### 4. **Gather the Results**:
   After processing all strings, we loop through the hash map and move each group of anagrams into the result vector `res`.

   ```cpp
   for (auto& [key, val] : m_map) res.emplace_back(std::move(val));
   ```

   - `std::move(val)`: This ensures that we move the vector of anagrams from the map to the result vector, avoiding unnecessary copies.

### 5. **Return the Result**:
   Finally, we return the `res` vector, which now contains all groups of anagrams.

   ```cpp
   return res;
   ```

---

### 6. **Custom Output Format**:
   The `operator<<` is overloaded to print the result in a readable format. It prints the anagram groups with appropriate curly braces and commas.

   ```cpp
   std::ostream& operator<<(std::ostream& out, std::vector<std::vector<std::string>> vv) {
       out << "{";
       for (char sep_1[]{0, ' ', 0}; const auto& v : vv) {
           out << sep_1 << "\n\t{";
           for (char sep_2[]{0, ' ', 0}; const auto& el : v)
               out << sep_2 << el, sep_2[0] = ',';
           out << "}";
           sep_1[0] = ',';
       }
       out << "\n}";
       return out;
   }
   ```

---

## Time and Space Complexity:

- **Time Complexity**:  
  - Sorting each string takes **O(k log k)** time, where `k` is the length of the string. Since there are `n` strings, the overall time complexity is **O(n * k log k)**, where `n` is the number of strings and `k` is the average length of the strings.

- **Space Complexity**:  
  - The space complexity is **O(n * k)** because the solution stores all the strings in the hash map and result vector, where `n` is the number of strings and `k` is the average length of the strings.

---

## Final Thoughts:

This solution efficiently groups anagrams by using a **hash map** where the key is the sorted string, allowing us to easily group anagrams together. The algorithm is time-efficient and scales well for moderate input sizes, with a time complexity of **O(n * k log k)**. By leveraging sorting to create a common key for anagrams, the solution effectively handles a variety of input scenarios, including edge cases like empty strings.