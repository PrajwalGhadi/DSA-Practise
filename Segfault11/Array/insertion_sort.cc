/**
 * Insertion Sort Algorithm
 * @file insertion_sort.cc
 * @author Rohit Gautam
 */

#include <iostream>

void swap(int& a, int& b) {
  int t;
  t = a, a = b, b = t;
}

/**
 * Sort an array using insertion sort algorithm.
 * The outer for loop runs for N-1 times.
 * In each iteration inner while loop is ran only is number is out of order.
 *
 * Time-Complexity: O(N^2)
 * Space-Complexity: O(1)
 *
 * @param arr unsorted/partially sorted input array.
 * @param size size of the array.
 */
void insertion_sort(int* arr, int size) {
  int count = 0;
  for (int i = 1; i <= size - 1; i++) {
    int current = arr[i];
    int prev = i - 1;
    while (prev >= 0 and arr[prev] > current) {
      count++;
      arr[prev + 1] = arr[prev];
      prev--;
    }
    arr[prev + 1] = current;
  }

  std::cout << "Total Iterations: " << count << '\n';
}

int main() {
  int arr[] = {1, 2, 3, 4, 6, 5};
  int size = sizeof(arr) / sizeof(int);
  insertion_sort(arr, size);

  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << '\n';
}