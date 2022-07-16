/**
 * Binary Search Algorithm
 * @file binary_search.cc
 * @author Rohit Gautam
 */

#include <iostream>

/**
 * Fast-Efficient Searching Algorithm, required the search space to sorted (monotonic).
 * Time-Complexity:- O(LogN) (worst-case), O(1) (best-case)
 * Space-Complexity:- O(1)
 *
 * @param arr Sorted array to search in
 * @param size Size of the array
 * @param target Value to be search in the array
 * @return index (position) of target value or -1
 */
int binary_search(int* arr, int size, int target) {
  int low = 0;
  int high = size - 1;
  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

int main() {
  int nums[] = {1, 2, 5, 8, 12, 44, 77, 89, 90, 99, 133, 234, 235, 445};
  int input;
  std::cin >> input;
  int index = binary_search(nums, sizeof(nums) / sizeof(int), input);
  if (index == -1) {
    std::cout << input << " not present in the array!\n";
  } else {
    std::cout << input << " found at position " << index << '\n';
  }
  return 0;
}
