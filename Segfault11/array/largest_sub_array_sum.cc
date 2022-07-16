/**
 * Problem: Compute the largest sub array sum
 * @file largest_sub_array_sum.cc
 * @author Rohit Gautam
 */

#include <iostream>

/**
 * Uses prefix-sum method to compute largest sub array sum.
 * An array of cumlative sum is computed before-hand in O(N) time,
 * from which largest sub array sum is computed.
 *
 * Time-Complexity: O(N^2)
 * Space-Complexity: O(N)
 *
 * @param arr input arr of integers
 * @param size input array size
 * @return largest sum of sub array
 */
int largest_sub_array_sum(int* arr, int size) {
  int prefix_sum[size] = {arr[0]};

  for (int i = 1; i < size; i++) {
    prefix_sum[i] = prefix_sum[i - 1] + arr[i];
  }

  int mx = 0;
  for (int i = 0; i < size; i++) {
    for (int j = i; j < size; j++) {
      int sum = (i > 0) ? prefix_sum[j] - prefix_sum[i - 1] : prefix_sum[0];
      mx = std::max(mx, sum);
    }
  }
  return mx;
}

/**
 * Compute largest sub array sum using Kadane's algorithm.
 * A running cumulative sum is maintained, which must be non-negative.
 *
 * Time-Complexity: O(N)
 * Space-Complexity: O(1)
 *
 * @param arr input arr of integers
 * @param size input array size
 * @return largest sum of sub array
 */
int kadanes_largest_sub_array_sum(int* arr, int size) {
  int cs = 0;
  int ms = 0;
  for (int i = 0; i < size; i++) {
    cs = std::max(0, cs + arr[i]);
    ms = std::max(ms, cs);
  }
  return ms;
}

int main() {
  int arr[] = {-4, 2, -2, 5, 6, -7, 1, 8};
  std::cout << "Max Sum: " << largest_sub_array_sum(arr, sizeof(arr) / sizeof(int)) << '\n';
  std::cout << "Max Sum: " << kadanes_largest_sub_array_sum(arr, sizeof(arr) / sizeof(int)) << '\n';

  return 0;
}