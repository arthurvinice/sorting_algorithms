# Sorting Algorithms Repository

This repository contains implementations of six sorting algorithms written in C++: Bubble Sort, Selection Sort, Insertion Sort, Shell Sort, Quick Sort, and Merge Sort.

## Algorithms

### 1. Bubble Sort
Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

- **Time Complexity**: O(n^2) in the worst and average case, O(n) in the best case (when the list is already sorted).

### 2. Selection Sort
Selection Sort is an in-place comparison sorting algorithm that divides the input list into two parts: a sorted sublist and an unsorted sublist. It repeatedly selects the smallest element from the unsorted sublist and swaps it with the leftmost unsorted element.

- **Time Complexity**: O(n^2) in all cases (worst, average, and best).

### 3. Insertion Sort
Insertion Sort is another simple sorting algorithm that builds the final sorted array one item at a time. It takes each element from the input list and inserts it into its correct position in the sorted array.

- **Time Complexity**: O(n^2) in the worst and average case, O(n) in the best case (when the list is nearly sorted).

### 4. Shell Sort
Shell Sort is an optimization of Insertion Sort that allows the exchange of items that are far apart. It starts by sorting pairs of elements far apart from each other and then progressively reduces the gap between elements to be compared.

- **Time Complexity**: O(n log^2 n) in the worst case, but can perform better than O(n^2) depending on the gap sequence used.

### 5. Quick Sort
Quick Sort is a divide-and-conquer algorithm that works by selecting a 'pivot' element from the list and partitioning the other elements into two sub-arrays according to whether they are less than or greater than the pivot. It then recursively sorts the sub-arrays.

- **Time Complexity**: O(n^2) in the worst case, but O(n log n) on average and in the best case.

### 6. Merge Sort
Merge Sort is also a divide-and-conquer algorithm that divides the input array into two halves, sorts each half separately, and then merges the sorted halves. It is known for its stability and guarantees a worst-case time complexity of O(n log n).

- **Time Complexity**: O(n log n) in all cases (worst, average, and best).

## Usage
Each sorting algorithm is implemented in a separate C++ file. You can run each file independently to see the algorithm in action on sample input arrays. Feel free to explore and compare the performance of these sorting algorithms!

## Contributing
If you'd like to contribute to this repository by adding more sorting algorithms or improving existing ones, please fork the repository and submit a pull request with your changes.

