/**
 * Problem: Given a string of repeating characters,
 * encode the string with the character and the no. of times it repeated.
 *
 * TC: O(N)
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
  string input;
  cin >> input;

  string output = "";
  for (int i = 0; input[i] != '\0'; i++) {
    int count = 1;
    while (i <= input.length() - 1 and input[i] == input[i + 1]) {
      count++, i++;
    }
    output += input[i];
    output += to_string(count);
  }

  cout << output << '\n';

  return 0;
}