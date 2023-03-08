#include <iostream>
#include <vector>

using namespace std;

void NhapMang(vector<vector<int>> &a)
{
	int dong;
	cout << "\nNhap vao so dong: ";
	cin >> dong;
	a.resize(dong);

	for(int i = 0; i < dong; i++)
	{
		int cot;
		cout << "\nNhap vao so cot cua dong " << i << ": ";
		cin >> cot;
		a[i].resize(cot);
		for(int j = 0; j < cot; j++)
		{
			cout << "\nNhap vao a[" << i << "][" << j << "] = ";
			cin >> a[i][j];
		}
	}
}

// define a function to check if a number is valid in a given position
bool is_valid(vector<vector<int>>& puzzle, int row, int col, int num) {
  // check if the number appears in the same row
  for (int i = 0; i < 9; i++) {
    if (puzzle[row][i] == num) {
      return false;
    }
  }
  // check if the number appears in the same column
  for (int i = 0; i < 9; i++) {
    if (puzzle[i][col] == num) {
      return false;
    }
  }
  // check if the number appears in the same 3x3 subgrid
  int start_row = (row / 3) * 3;
  int start_col = (col / 3) * 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (puzzle[start_row + i][start_col + j] == num) {
        return false;
      }
    }
  }
  // if the number is not in the same row, column, or 3x3 subgrid, it is valid
  return true;
}

// define a function to solve the sudoku puzzle using backtracking
int solve(vector<vector<int>>& puzzle, int row, int col) {
  // base case: if we have filled all the cells, we have found a solution
  if (row == 9) {
    return 1;
  }

  // if the cell is already filled, move on to the next cell
  if (puzzle[row][col] != 0) {
    if (col == 8) {
      return solve(puzzle, row + 1, 0);
    } else {
      return solve(puzzle, row, col + 1);
    }
  }

  // try filling the cell with each possible number and count the number of solutions
  int count = 0;
  for (int num = 1; num <= 9; num++) {
    if (is_valid(puzzle, row, col, num)) {
      puzzle[row][col] = num;
      if (col == 8) {
        count += solve(puzzle, row + 1, 0);
      } else {
        count += solve(puzzle, row, col + 1);
      }
      puzzle[row][col] = 0;
    }
  }
  return count;
}

// define a function to compute the number of solutions for a given sudoku puzzle
int sudoku_solutions(vector<vector<int>> puzzle) {
  // start the solving process at the first cell (row 0, col 0)
  return solve(puzzle, 0, 0);
}

int main() {
  
  vector<vector<int>> puzzle(9, vector<int>(9));

  // input the puzzle
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> puzzle[i][j];
    }
  }

  cout << sudoku_solutions(puzzle) << endl; // should print 64
  return 0;
}

