/**
 * Problem: Given an array containing N intergers,
 * and an number S denoting a target Sum.
 *
 * Find all distinct integers that can add up to form target sum.
 * The number in each triplet should be ordered in ascending order,
 * and triplets should be ordered too.
 *
 * Return empty array if no such triplet exists.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Select ith element and do a two pointer from i+1 and n-1.
 * Make sure to sort the array before-hand.
 *
 * Time-Complexity: O(N*LogN)
 *
 * @param arr input array.
 * @param target target sum.
 * @return 2d vector containing all triplets.
 */
vector<vector<int>> triplet(vector<int>& arr, int target) {
  int n = arr.size();
  vector<vector<int>> result;
  sort(arr.begin(), arr.end());
  for (int i = 0; i <= n - 3; i++) {
    int p = i + 1;
    int q = n - 1;
    while (p < q) {
      int sum = arr[i] + arr[p] + arr[q];
      if (sum == target) {
        result.push_back({arr[i], arr[p], arr[q]});
        p++, q--;
      } else if (sum < target) {
        p++;
      } else if (sum > target) {
        q--;
      }
    }
  }
  return result;
}

int main() {
  vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 18};
  int target = 18;

  auto result = triplet(arr, target);

  for (auto& row : result) {
    cout << "(";
    for (auto& x : row) {
      cout << x << ", ";
    }
    cout << ")\n";
  }
  return 0;
}