# LeetCode Solutions in C++

**NOTE:** For convenience, use **C++20** for all the following solutions.

The folder structure for this repository is organized as follows:

```
.
├── general
│   ├── easy
│   ├── medium
│   └── hard
│   
├── leetcode_75
│   
├── top_interview_150
│   
└── top_mentions
```

- **general**: This folder contains problems categorized by difficulty levels:
  - **easy**: Problems that are considered easy to solve.
  - **medium**: Problems that are moderately challenging.
  - **hard**: Problems that require advanced techniques and optimizations.

- **leetcode_75**: This folder contains solutions from the "Leetcode 75" list, a curated list of 75 essential Leetcode problems.
  
- **top_interview_150**: This folder contains solutions from the "Top Interview Questions" list, which includes the most commonly asked Leetcode interview questions.

- **top_mentions**: These are not official LeetCode questions, but they are worth exploring.
---

### Problem Naming Convention

Each problem file follows the naming convention:

```
<leetcode_number>_<problem_title>.cpp
```

For example:
- **1_two_sum.cpp**: The problem with Leetcode number 1, titled "Two Sum".

This naming format ensures that you can easily identify and navigate through the problems based on their Leetcode problem number and title.

---

### File Contents

Each problem folder contains:

- A **C++ source file** (`<problem_number>_<problem_title>.cpp`) with the solution implementation.
- A **Markdown file** (`<problem_number>_<problem_title>.md`) that explains the **intuition** behind the solution approach, often with a detailed breakdown of the logic.

Some problems are implemented using **both brute force** and **optimized approaches** to illustrate the difference in time and space complexity. This allows you to compare the two methods and understand how to improve the solution. Example:

```cpp
class Solution {
public:
    // Optimized solution
    void problem() {
        // Optimized approach logic
    }

    // Brute force solution
    void problem_bruteforce() {
        // Brute force approach logic
    }
};
```

- The **`problem()`** function typically implements the optimized approach, and the **`problem_bruteforce()`** function shows a more straightforward but less efficient brute force solution.

---

### How to Navigate the Repository

1. **Explore by Difficulty**:  
   In the **general** folder, you can find problems organized by their difficulty (easy, medium, hard). This organization helps you choose problems based on your skill level or how challenging you want the problem to be.

2. **Curated Lists**:  
   If you're looking for specific problems to improve your coding skills, the **leetcode_75** and **top_interview_150** folders are great places to start. These lists focus on important problems often asked in interviews and cover a wide range of concepts.

3. **Read Problem Intuition**:  
   Each problem has a corresponding markdown file explaining the intuition behind the solution. This helps you understand the reasoning and approach before jumping into the code itself.

---

### Code Quality

- **Clarity**: The code is written to be as clear and readable as possible. Each solution includes relevant comments explaining the steps and logic behind the code.
- **Efficiency**: Whenever possible, an optimized solution is provided. We prioritize writing efficient solutions in terms of time and space complexity, but brute force solutions are included when helpful to understand the problem.
- **Test Cases**: Each solution is tested against multiple test cases to ensure correctness and edge case handling.

---

### How to Contribute

1. **Fork the Repository**: You can fork the repository to add your own solutions or improve existing ones.
2. **Add a New Solution**: When adding a new problem, make sure to follow the naming convention and provide an explanation of the approach in a corresponding markdown file.
3. **Submit a Pull Request**: Once you've added a solution or fixed an issue, feel free to submit a pull request for review.