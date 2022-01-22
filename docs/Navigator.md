# Navigator
This file contains a list of CP topics and techniques that I can refer to if I get stuck on a practice problem.

# Sorts
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
  ### 2D Prefix Sums
  - useful for counting coordinates in some range
  - compress points
  - for range updates, set deltas +1 on bottom-left and top-right and -1 on top-left and bottom-right. then prefix sum. (USACO #919)
  ### Max
  - You can prefix sum on the maximum value

# Graph Algorithms
## DFS
  - Depth-first search recursively traverses a graph.
  - Look for ways to move code into the dfs instead of repetitive clearing operations.
  - Think about storing what component each node belongs too?
  - check to make sure you really need to dfs. see if you can dfs iteratively beforehand.

### Flood Fill
  - DFS on a grid

# Tree Algorithms
  - empty for now because i don't know that much CP

# Dynamic Programming
  Max # of selected elements such that each selected subarray with size > 1 has non-negative sum.
  ```c++
  int s = n, sm = 0, mn = 2e9; // s = # selected, sm = sum of current segment, mn = min sub array sum in current segment
  for(int i = 0; i < n; i++){
    if(a[i] + mn < 0){
      s--; sm = 0; mn = 2e9;
    } else {
      sm += a[i]; mn = mn < 0 ? mn + a[i] : a[i];
    }
  }
  ```

# Bitwise
  - Let p be the bitwise OR product of pairwise AND in an array. The k-th bit of p is set iff the # of elements in the array with the k-th bit set is > 1. (Source: CodeChef START21C ANDORUNI)