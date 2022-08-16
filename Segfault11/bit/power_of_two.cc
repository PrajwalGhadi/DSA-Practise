#include <iostream>

using namespace std;

bool power_of_two(const int n) {
  return !(n & (n - 1));
}

int main() {
  int n;
  cin >> n;

  cout << boolalpha << power_of_two(n) << '\n';
  return 0;
}