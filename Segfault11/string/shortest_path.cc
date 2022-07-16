/**
 * Problem: Given a string of directions, compute the shortest path (displacement).
 *
 * TC: O(N)
 *
 * Input: SNNNEEWE
 * Output: NNEE
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
  string directions;

  cin >> directions;

  int x = 0, y = 0;
  for (auto& d : directions) {
    switch (d) {
      case 'S':
        y--;
        break;
      case 'N':
        y++;
        break;
      case 'W':
        x--;
        break;
      case 'E':
        x++;
        break;
    }
  }

  // cout << "Y: " << y << ", X: " << x << '\n';

  while (y != 0) {
    if (y > 0) {
      cout << 'N';
      y--;
    } else {
      cout << 'S';
      y++;
    }
  }

  while (x != 0) {
    if (x > 0) {
      cout << 'E';
      x--;
    } else {
      cout << 'W';
      x++;
    }
  }
  return 0;
}