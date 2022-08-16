#include <iostream>

using namespace std;

int fast_exponentiation(int n, int p) {
  int ans = 1;
  while (p > 0) {
    if (p & 1) {
      ans = ans * n;
    }
    n = n * n;
    p = p >> 1;
  }
  return ans;
}

int main() {
  int n, p;
  cin >> n >> p;
  cout << fast_exponentiation(n, p) << '\n';
  return 0;
}