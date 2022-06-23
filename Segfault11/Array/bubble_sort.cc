/**
 * Bubble Sort Algorithm
 * @file bubble_sort.cc
 * @author Rohit Gautam
 */

#include <iostream>

void swap(int& a, int& b) {
  int t;
  t = a, a = b, b = t;
}

/**
 * Sort an array using bubble sort algorithm.
 * The outer for loop runs for N-1 times.
 * In each iteration inner for loop compare two adjacent numbers,
 * and move the largest/smallest to the end.
 *
 * Time-Complexity: O(N^2)
 * Space-Complexity: O(1)
 *
 * @param arr unsorted input array.
 * @param size size of the array.
 * @param reverse bool flag indicating to sort in reverse (descending order).
 */
void bubble_sort(int* arr, int size, bool reverse = false) {
  for (int i = 1; i < size; i++) {
    for (int j = 0; j < size - i; j++) {
      if (reverse) {
        if (arr[j] < arr[j + 1]) {
          swap(arr[j], arr[j + 1]);
        }
      } else {
        if (arr[j] > arr[j + 1]) {
          swap(arr[j], arr[j + 1]);
        }
      }
    }
  }
}

int main() {
  int arr[] = {-2, 3, 4, -1, 5, -12, 6, 1, 3};
  int size = sizeof(arr) / sizeof(int);
  bubble_sort(arr, size, true);

  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << '\n';
}