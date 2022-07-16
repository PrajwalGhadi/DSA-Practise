/**
 * Problem: Write a function that searches for an element in
 * row wise & column wise sorted 2D array.
 * AKA Staircase Search
 *
 * @file sorted_array_search.cc
 * @author Rohit Gautam
 */

#include <iostream>
#include <utils.hh>

using namespace std;

/**
 * Check if target is smaller then move left else move downward.
 *
 * Time Complexity: O(M+N), where M is nrows & n is ncols.
 *
 *
 * @param arr int [][]
 * Sorted 2d array
 * @param target int
 * Element to search
 *
 * @return pair of resulting indexes
 */
template <size_t rows, size_t cols>
pair<int, int> sorted_array_search(int (&arr)[rows][cols], int target) {
  int nrows = sizeof(arr) / sizeof(arr[0]);
  int ncols = sizeof(arr[0]) / sizeof(arr[0][0]);

  if (target < arr[0][0] or target > arr[nrows - 1][ncols - 1]) {
    return {-1, -1};
  }

  int i = 0;
  int j = ncols - 1;

  while (i <= nrows - 1 and j >= 0) {
    if (arr[i][j] == target) {
      return {i, j};
    } else if (arr[i][j] > target) {
      j--;
    } else {
      i++;
    }
  }
  return {-1, -1};
}

int main() {
  int arr[][4] = {
      {10, 20, 30, 40},
      {15, 25, 35, 45},
      {27, 29, 37, 48},
      {32, 33, 39, 50},
  };
  auto result = sorted_array_search(arr, 33);
  cout << "[ " << result.first << ", " << result.second << " ]\n";

  return 0;
}