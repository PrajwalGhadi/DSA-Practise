/**
 * Selection Sort Algorithm
 * @file selection_sort.cc
 * @author Rohit Gautam
 */

#include <iostream>

void swap(int& a, int& b) {
  int t;
  t = a, a = b, b = t;
}

/**
 * Sort an array using selection sort algorithm.
 * Repeatedly find the minimum element from unsorted part
 * and putting it in the beginning.
 *
 * Time-Complexity: O(N^2)
 * Space-Complexity: O(1)
 *
 * @param arr unsorted sorted input array.
 * @param size size of the array.
 */
void selection_sort(int* arr, int size) {
  int count = 0;
  for (int i = 0; i <= size - 2; i++) {
    int mn = i;
    for (int j = i + 1; j <= size - 1; j++) {
      if (arr[j] < arr[mn]) {
        mn = j;
      }
      count++;
    }
    swap(arr[i], arr[mn]);
  }

  std::cout << "Total Iterations: " << count << '\n';
}

int main() {
  int arr[] = {1, 9, 43, 2, 3, 33, 8, 4, 6, 5};
  int size = sizeof(arr) / sizeof(int);
  selection_sort(arr, size);

  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << '\n';
}