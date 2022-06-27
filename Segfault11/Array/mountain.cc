/**
 * Problem: Write a function that takes input an array of distinct integers,
 * and returns the length of the highest mountain.
 *
 * * A mountain is defined as adjacent integers that are strictly increasing
 *   until they reach a peak, at which they become strictly decreasing.
 *
 * * Atleast 3 numbers are required to form a mountain.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Iterate over the array and find the peak i.e a[i-1] < a[i] > a[i+1],
 * Find the length of the mountain by traversing down from both sides.
 *
 * TC: O(N)
 *
 * @param arr input arr
 * @return length of largest mountain
 */
int mountain(vector<int>& arr) {
  int n = arr.size();
  int largest = 0;
  for (int i = 1; i <= n - 2;) {
    if (arr[i - 1] < arr[i] and arr[i + 1] < arr[i]) {
      int length = 1;
      int j = i;
      while (j >= 1 and arr[j - 1] < arr[j]) {
        length++, j--;
      }
      while (i <= n - 2 and arr[i + 1] < arr[i]) {
        length++, i++;
      }
      largest = max(largest, length);
    } else {
      i++;
    }
  }
  return largest;
}

int main() {
  vector<int> arr{6, 3, 1, 2, 3, 4, 5, 4, 2, 1, 0, 3, 4, 3, -2, 4};

  int result = mountain(arr);
  cout << "Highest mountain: " << result << '\n';
  return 0;
}
