/**
 * Counting Sort Algorithm
 * @file counting_sort.cc
 * @author Rohit Gautam
 */

#include <climits>
#include <iostream>

/**
 * Compute min & max element of an array.
 *
 * @param start pointer to the start of the array.
 * @param end pointer to the end of the array.
 * @return pair of min & max value from the array.
 */
std::pair<int, int> minmax_element(int* start, int* end) {
  int mn = INT_MAX, mx = INT_MIN;
  while (start != end) {
    if (*start < mn) {
      mn = *start;
    }
    if (*start > mx) {
      mx = *start;
    }
    start++;
  }
  return {mn, mx};
}

/**
 * Create a hash table of size range of values in the array and fill it.
 * Iterate over the hash table and fill the original array in order.
 *
 * TC: O(N+R) where R is the range of values in the array.
 * SC: O(R)
 *
 * @param arr pointer to the input array of dtype int.
 * @param size no. of element inside the given array.
 */
void counting_sort(int* arr, int size) {
  auto [mn, mx] = minmax_element(arr, arr + size);
  int len = abs(mx - mn);
  int* H = new int[len + 1];

  for (int i = 0; i <= size - 1; i++) {
    H[arr[i] - mn]++;
  }

  int c = 0;
  for (int i = 0; i <= len; i++) {
    while (H[i]-- > 0) {
      arr[c] = i + mn;
      c++;
    }
  }
}

int main() {
  int arr[] = {10, 2, 3, 2, -42, 0, -6, 100, -65};
  int size = sizeof(arr) / sizeof(int);
  counting_sort(arr, size);

  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << '\n';
}