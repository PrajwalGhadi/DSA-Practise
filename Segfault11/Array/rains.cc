/**
 * Problem: Given a non-negative integers representing an elevation map
 * where the width of each bar is 1,
 * compute how much water it can trap after raining.
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Each bar can trap the minimum of the two adjacent bars minus current bar.
 * Pre-compute the maximum of all the bars from left & right.
 *
 * @param arr input arr
 * @retur total rain water trapped between bars
 */
int rain(vector<int>& arr) {
  int n = arr.size();
  vector<int> L(n, 0), R(n, 0);
  L[0] = arr[0];
  R[n - 1] = arr[n - 1];
  for (int i = 1; i <= n - 1; i++) {
    L[i] = max(L[i - 1], arr[i]);
    R[n - i - 1] = max(R[n - i], arr[n - i - 1]);
  }

  int total_water = 0;
  for (int i = 0; i <= n - 1; i++) {
    total_water += min(L[i], R[i]) - arr[i];
  }
  return total_water;
}

int main() {
  vector<int> arr{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

  int result = rain(arr);
  cout << "Trapped rain water: " << result << '\n';
  return 0;
}