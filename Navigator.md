# Navigator
This file contains a list of CP topics and techniques that I can refer to if I get stuck on a practice problem.

# Sorts
## Quick Sort
  - Time Complexity: O(nlog(n))
## Merge Sort
  - Time Complexity: O(nlog(n))
## Cyclic Sort
  - Unstable sorting algorithm - doesn't always preserve order for elements that are equal
  - Time Complexity: O(n)
  - Uses a heuristic to sort

# Searches
## Binary Search
  - Time Complexity: O(log(n))
  - Search on intended answer. Look for ways to create a monotonic function given some parameters.
  - Try thinking backwards (pass result as parameter and use constraints for function)
  - Can be used to find the maximum value of an increasing-then-decreasing function or minimum value of decreasing-then-increasing function
## Linear Search / Sweep
  - Simple iteration

# Traversals
## 2 pointers
  - move 2 monotonic pointers across array to guarantee linear time

# Range Sum Query Algorithms
## Prefix Sums
  - store an array such that ar[k] is the sum of the first kth elements in the original array
  - useful for counting objects in a certain range

# Graph Algorithms
## DFS
  - Depth-first search recursively traverses a graph
### Flood Fill
  - DFS on a grid

# Tree Algorithms
  - empty for now because i don't know that much CP
