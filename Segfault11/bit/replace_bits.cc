#include <iostream>

using namespace std;

void clear_bits_in_range(int& n, int i, int j) {
  int mask = ((1 << i) - 1) | (-1 << (j + 1));
  n = n & mask;
}

// n: 0 0 0 [1 1 0] 0 1
// m: 1 0 1
// n: 0 0 0 [1 0 1] 0 1

void replace_bits(int& n, int m, int i, int j) {
  clear_bits_in_range(n, i, j);
  n = n | (m << i);
}

int main() {
  int n = 25;
  int m = 5;
  int i = 2, j = 4;

  replace_bits(n, m, i, j);
  cout << n << '\n';  // 21

  return 0;
}