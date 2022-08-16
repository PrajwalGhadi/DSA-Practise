#include <iostream>

using namespace std;

long long decimal_to_binary(int n) {
  long long binary_sequence = 0;
  long long pow = 1;
  while (n > 0) {
    binary_sequence = (n & 1) * pow + binary_sequence;

    pow = pow * 10;
    n = n >> 1;
  }

  return binary_sequence;
}

int main() {
  int n;
  cin >> n;
  cout << decimal_to_binary(n) << '\n';

  return 0;
}
