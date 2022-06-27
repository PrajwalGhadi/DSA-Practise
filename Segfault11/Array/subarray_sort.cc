/**
 * Problem: Given an array of size atleast two, find smallest subarray
 * that needs to be sorted in-place so that entire input array becomes sorted.
 *
 * If input array is already sorted, the function should return [-1, -1],
 * otherwise return the start & end index of smallest subarray.
 */

#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Check for out of order elements.
 *
 * @param arr input arr.
 * @param idx index of the element to check for out ot order position.
 * @return boolean indicating element out of order.
 */
bool out_of_order(vector<int>& arr, int idx) {
  if (idx == 0) {
    return arr[0] > arr[1];
  } else if (idx == arr.size() - 1) {
    return arr[idx] < arr[idx - 1];
  }
  return arr[idx] > arr[idx + 1] or arr[idx] < arr[idx - 1];
}

/**
 * Find the smallest & largest out of order number and
 * check for the correct position of those out of order number.
 *
 * TC: O(N)
 *
 * @param arr input arr
 * @return return the start & end index of smallest subarray.
 */
pair<int, int> subarray_sort(vector<int>& arr) {
  int n = arr.size();
  int largest = INT_MIN;
  int smallest = INT_MAX;

  for (int i = 0; i <= n - 1; i++) {
    if (out_of_order(arr, i)) {
      smallest = min(smallest, arr[i]);
      largest = max(largest, arr[i]);
    }
  }

  if (smallest == INT_MAX) {
    return {-1, -1};
  }

  int i = 0;
  while (smallest > arr[i]) {
    i++;
  }

  int j = n - 1;
  while (largest < arr[j]) {
    j--;
  }
  return {i, j};
}

int main() {
  vector<int> arr{1, 2, 3, 5, 6, 7, 4, 8, 9, 10, 11};

  auto result = subarray_sort(arr);

  cout << "[" << result.first << ", " << result.second << "]\n";

  return 0;
}
