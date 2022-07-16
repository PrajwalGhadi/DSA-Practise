#include <iostream>
#include <string>
#include <unordered_set>
#include <utils.hh>

using namespace std;

string super_reduced_string(string s) {
  int n = s.length();
  const int i = 0;
  // while (s[i]) {
  //   cout << s[i];
  // }

  for (const auto& x : s) {
    auto a = x;
    cout << a << " - " << type_name<decltype(&a)>() << '\n';
  }
  cout << s << '\n';

  return s;
}

int main() {
  string s;

  getline(cin, s);

  string result = super_reduced_string(s);

  // cout << result << '\n';
  return 0;
}
