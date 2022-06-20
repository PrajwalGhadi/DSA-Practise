/**
 * Reverse Array Algorithm
 * @file reverse_array.cc
 * @author Rohit Gautam
 */

#include <iostream>

template <typename T>
void swap(T& a, T& b) {
  T t;
  t = a, a = b, b = t;
};

/**
 * Reverse an array in-place using two-pointer approach.
 * Time-Complexity: O(N)
 * Space-Complexity: O(1)
 *
 * @param arr input array of dtype like int, char, string.
 * @param size size of the array
 */
template <typename T>
void reverse_array(T* arr, size_t size) {
  int p = 0;
  int q = size - 1;

  while (p < q) {
    swap<T>(arr[p], arr[q]);
    p++, q--;
  }
}

int main() {
  // int arr[] = {1, 2, 5, 8, 12, 44, 77, 89, 99, 133, 234};
  char arr[] = {'r', 'a', 'c', 'e', 'c', 'a', 'r'};

  std::cout << "Before Reverse:\n";
  for (auto x : arr) {
    std::cout << x << ", ";
  }
  std::cout << "\b\b\n";

  reverse_array(arr, sizeof(arr) / sizeof(decltype(arr[0])));

  std::cout << "After Reverse:\n";
  for (auto x : arr) {
    std::cout << x << ", ";
  }
  std::cout << "\b\b\n";
}