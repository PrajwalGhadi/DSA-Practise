/**
 * Shift Left:
 * n << i -> n * 2^i
 * 10 << 1 -> 10 * 2^1
 *
 * 0 0 0 0 1 0 1 0 -> 10
 * 0 0 0 1 0 1 0 0 -> 20
 *
 * Shift Right:
 * n >> i -> n / 2^i
 * 10 >> 1 -> 10 / 2^1
 *
 * 0 0 0 0 1 0 1 0 -> 10
 * 0 0 0 0 0 1 0 1 -> 5
 */

#include <iostream>

using namespace std;

bool is_odd(const int n) {
  return n & 1;
}

bool get_ith_bit(const int n, int i) {
  int mask = 1 << i;
  return n & mask;
}

void set_ith_bit(int& n, int i) {
  int mask = 1 << i;
  n = n | mask;
}

void clear_ith_bit(int& n, int i) {
  int mask = ~(1 << i);
  n = n & mask;
}

void update_ith_bit(int& n, int i, bool v) {
  clear_ith_bit(n, i);
  int mask = v << i;
  n = n | mask;
}

void clear_last_i_bits(int& n, int i) {
  int mask = -1 << i;
  n = n & mask;
}

// 0 0 0 1 1 1 1 1 -> 31
// 1 1 1 1 0 0 0 1
// 0 0 0 1 0 0 0 1 -> 17

void clear_bits_in_range(int& n, int i, int j) {
  int mask = ((1 << i) - 1) | (-1 << (j + 1));
  n = n & mask;
}

int main() {
  int n;
  cin >> n;
  clear_bits_in_range(n, 1, 3);
  cout << n << '\n';

  return 0;
}
