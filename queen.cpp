// Example program
#include <iostream>
#include <string>
#define N 8

using namespace std;

int row, col, numQueen;
int board[9][9] = { };

bool putQueen() {
	if (!board[row][col]) {
		for (int i = row + 1; i <= N; i++) {
			if (!board[i][col]) {
				board[i][col] = row;
			}
		}
		for (int i = row + 1; i < row + col; i++) {
			if (!board[i][col]) {
				board[i][col] = row;
			}
		}
		return true;
	} else {
		return false;
	}
}

bool removeQueen() {
}

int main() {
	while (row) {
		while (col < 9) {    //
			// put next queen in column col (and next row)
			putQueen();
			if (putQueenSuccessed) {
				if (numQueen == N) {   // if all queens put on board
					printString();
					removeQueen();  // remove the current queen
					col++;
				} else {
					row++;  // increase row, try to put next queen
				}
			} else {
				// revert board
				removeQueen();
				//
				col++;
			}
		}
		row--;
	}

}
