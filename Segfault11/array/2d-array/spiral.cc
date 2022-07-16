/**
 * Problem: Print all array element in a spiral order.
 * Start from top-left corner goes to right,
 * proceed in a spiral pattern until every element is visited.
 *
 * @file spiral.cc
 * @author Rohit Gautam
 */

#include <iostream>
#include <utils.hh>

using namespace std;

/**
 * Loop over all the sides of the 2D array,
 * while increasing/decreasing the starting & ending index.
 *
 * Time-Complexity: O(N)
 *
 * @param arr input array
 */
template <size_t rows, size_t cols>
void spiral(int (&arr)[rows][cols]) {
  int nrows = sizeof(arr) / sizeof(arr[0]);
  int ncols = sizeof(arr[0]) / sizeof(arr[0][0]);

  int start_row = 0;
  int start_col = 0;
  int end_row = nrows - 1;
  int end_col = ncols - 1;

  while (start_row <= end_row and start_col <= end_col) {
    REPL (col, start_col, end_col) {
      cout << arr[start_row][col] << ", ";
    }

    REPL (row, start_row + 1, end_row) {
      cout << arr[row][end_col] << ", ";
    }

    REPD (col, end_col - 1, start_col) {
      if (start_row == end_row) {
        break;
      }
      cout << arr[end_row][col] << ", ";
    }

    REPD (row, end_row - 1, start_row + 1) {
      if (start_col == end_col) {
        break;
      }
      cout << arr[row][start_col] << ", ";
    }

    start_row++;
    start_col++;
    end_row--;
    end_col--;
  }
}

int main() {
  int arr[][5] = {
      {01, 02, 03, 04, 05}, {16, 17, 18, 19, 06}, {15, 24, 25, 20, 07}, {14, 23, 22, 21, 8}, {13, 12, 11, 10, 9}};

  spiral(arr);

  return 0;
}