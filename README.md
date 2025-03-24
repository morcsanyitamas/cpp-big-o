# Big-O Notation

Big-O notation is a way to describe how the performance of an algorithm changes as the size of the input grows. It helps us understand the **time complexity** (how long an algorithm takes to run) and **space complexity** (how much memory it uses).

## Why is Big-O Important?
When writing code, it's important to know how efficient it is. For example:
- Will it run quickly for large inputs?
- Will it use too much memory?

Big-O notation gives us a way to compare [algorithms](https://www.bigocheatsheet.com/) and choose the best one for a specific problem.

## Common Big-O Complexities

### 1. O(1) - Constant Time
The algorithm takes the same amount of time, no matter the input size.<br>
Typical examples include accessing an element in an array.
```cpp
int arr[] = {1, 2, 3, 4, 5};
int x = arr[2];
```

### 2. O(log n) - Logarithmic Time
The algorithm reduces the size of the input in each step, often by half.<br>
Typical examples include binary search.
```cpp
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return nullptr;
}
```

### 3. O(n) - Linear Time
The algorithm's runtime grows linearly with the input size.<br>
Typical examples include iterating through an array.
```cpp
int findMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    return maxVal;
}
```

### 4. O(n²) - Quadratic Time
The algorithm processes pairs of elements, often using nested loops.<br>
Typical examples include bubble sort.
```cpp
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```

### 5. O(2ⁿ) - Exponential Time
The algorithm doubles the work for each additional element in the input.<br>
Typical examples include recursive Fibonacci.
```cpp
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```
Explanation: Each call to `fibonacci` doubles the number of recursive calls. The total number of **function execution** is O(2ⁿ).
```
fibonacci(5)
├── fibonacci(4)
│   ├── fibonacci(3)
│   │   ├── fibonacci(2)
│   │   │   ├── fibonacci(1) -> 1
│   │   │   └── fibonacci(0) -> 0
│   │   └── fibonacci(1) -> 1
│   └── fibonacci(2)
│       ├── fibonacci(1) -> 1
│       └── fibonacci(0) -> 0
└── fibonacci(3)
    ├── fibonacci(2)
    │   ├── fibonacci(1) -> 1
    │   └── fibonacci(0) -> 0
    └── fibonacci(1) -> 1
```

## Space Complexity

Space complexity measures how much memory an algorithm uses. For example:
* O(1): Uses a constant amount of memory (e.g., variables).
* O(n): Uses memory proportional to the input size (e.g., arrays).

### O(1) - Constant Space Complexity
```cpp
int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
```

### O(n) - Linear Space Complexity
```cpp
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```
Explanation: The total number of stack frames is dependent on the **depth of the call stack**, which is O(n).

## Assignments
The current implementation of the recursive Fibonacci function has poor time complexity O(2ⁿ) and space complexity O(n) because it recalculates the same values multiple times and uses a lot of memory for recursive calls.

Your task is to optimize the Fibonacci function to improve its performance. Try to figure out the time and space complexity of the following approaches:
* Iterative Approach
* Naive Recursive Approach
* Recursive Approach with Memoization
* Tail Recursive Approach

Write the optimized Fibonacci function in C++ and test it with different input values.