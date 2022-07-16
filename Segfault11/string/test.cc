#include <iostream>
#include <string>

using namespace std;
int main() {
  string line = "ATTENTION: .";
  string word = "T";
  int index = line.find(word);
  int i = 0;
  while (index != -1) {
    cout << ++i << ": " << index << '\n';
    index = line.find(word, index + 1);
  }
  return 0;
}