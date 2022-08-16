/**
 * Write a function to count set bits in a number!
 *
 */

#include <iostream>
#include "utils.hh"

using namespace std;
// 0 1 1 0 0 1 0 0
// 0 0 0 0 0 0 0 1

int count_set_bits(int n) {
  int count = 0;
  while (n > 0) {
    count += n & 1;
    n = n >> 1;
  }
  return count;
}

int count_set_bits_faster(int n) {
  int count = 0;
  while (n > 0) {
    n = n & (n - 1);
    count++;
  }
  return count;
}

int main() {
  int n;
  cin >> n;
  cout << count_set_bits(n) << '\n';
  cout << count_set_bits_faster(n) << '\n';
  return 0;
}