/**
 * Problem: Given an array containing N integers, find the length of longest band.
 *
 * A band is defined as a subsequence which can be reordered in such a manner
 * all elements appear consecutive (i.e. with absolute difference of 1 between
 * neighbouring elements)
 *
 * A longest band is the band (subsequence) which contains maximum integers.
 */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * Insert element in an unordered_set for O(1) lookup,
 * find the starting point of the band by searching for a[i]-1 in the set.
 * Once the starting point is found count consecutive elements.
 *
 * TC: O(N)
 * SP: O(N)
 *
 * @param arr input arr
 * @return largest band
 *
 */
int largest_band(vector<int>& arr) {
  int n = arr.size();
  unordered_set<int> uset;
  uset.insert(arr.begin(), arr.end());
  int largest = 0;
  for (int i = 0; i <= n - 1; i++) {
    int spc = arr[i] - 1;
    if (uset.find(spc) == uset.end()) {
      int count = 1;
      int nxtno = arr[i] + 1;
      while (uset.find(nxtno) != uset.end()) {
        count++, nxtno++;
        uset.erase(spc);
      }
      largest = max(largest, count);
    }
  }
  return largest;
}

int main() {
  vector<int> arr{9, 3, 1, 10, 2, 0, 5, 16, 4, 12, 7, 6};

  int result = largest_band(arr);
  cout << "Largest band: " << result << '\n';
  return 0;
}