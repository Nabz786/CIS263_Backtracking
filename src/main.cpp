#include <string>
#include <iostream>
#include <vector>
/**********************************************************************************
 *This file houses the back tracking algorithm to sort and create a new sudoku
 *board with given data.
 *@version Winter 2018
 *@author Nabeel Vali, Runquan Ye
 *********************************************************************************/

bool isFinished(int board[9][9]);
void printBoard(int board[9][9]);
bool solveBoard(int board[9][9]);
bool checkRow(int board[9][9], int row,  int value);
bool checkColumn(int board[9][9], int col, int value);
bool isValidOption(int board[9][9], int row, int col, int value);
bool checkThreeBox(int board[9][9], int row, int col, int value);
void setEmptyCell(int board[9][9], int row, int col);
void backtracking (int board[9][9]);

/**********************************************************************************
 * The main method initiates the program by inputting the partially filled board
 * then initiates the backtracking algorithm.
 **********************************************************************************/
int main(int argc, char ** argv){

	int board[9][9] ={{ 0, 3, 0, 0, 0, 0, 0, 2, 0 },
                   	 { 0, 9, 0, 0, 0, 0, 0, 8, 5 },
                   	 { 5, 0, 0, 0, 8, 0, 4, 0, 0 },
                   	 { 4, 0, 7, 2, 0, 6, 8, 9, 0 },
                   	 { 0, 1, 0, 8, 0, 9, 0, 4, 0 },
                   	 { 0, 8, 9, 5, 0, 1, 3, 0, 2 },
                   	 { 0, 0, 3, 0, 1, 0, 0, 0, 9 },
                   	 { 9, 4, 0, 0, 0, 0, 0, 1, 0 },
                   	 { 0, 7, 0, 0, 0, 0, 0, 3, 0 }};

	solveBoard(board);
}

/*********************************************************************************
 * The method checks each column for a duplicate value.
 * @param: int[][], board, the 2D array board 
 * @param: int, col, the number of column
 * @param: int, value, the value we will check for duplicates of
 * @returns: bool, true if no match was found, false if there was a duplicate value
 **********************************************************************************/
bool checkColumn(int board[9][9], int col, int value){

	for(int i = 0; i <9; i++) {
		if (board[i][col] == value) {
			return false;
		}
	}
	return true;
}

/*********************************************************************************
 * The method checks each row for a duplicate value.
 * @param: int[][], board, the 2D array board 
 * @param: int, row, the row to check
 * @param: int, value, the value we will check for duplictes of
 * @returns: bool, true if no match was found, false if there was a duplicate value 
 **********************************************************************************/
bool checkRow(int board[9][9], int row, int value){

	for(int i = 0; i < 9; i++) {
		if(board[row][i] == value) {
			return false;
		}
	}
	return true;
}

/*********************************************************************************
 * This method aims to fill in the rest of the board using backtracking
 * @param: int[][], board, the 2D array board 
 * @returns: bool, true if the board was solved, false if the board is unsolved
 **********************************************************************************/
bool solveBoard(int board[9][9]){
	
	if(isFinished(board)) {
		printBoard(board);
		return true;
	} else {
		int eRow, eCol;		

		for(int row = 0; row < 9; row++) {
			for(int col = 0; col < 9; col++) {
				if(board[row][col] == 0) {
					eRow = row;
					eCol = col;
					break;	
				}
			}
		}		

		for(int i = 1; i <= 9; i++){	
			if(isValidOption(board, eRow, eCol, i)) {
				board[eRow][eCol] = i;
				if(solveBoard(board)) {
					return true;
				} else {
					setEmptyCell(board, eRow, eCol);
				}
			}
		}
		return false;
	}
}

/*********************************************************************************
 * This method checks if the value we wish to insert will be valid, we verify
 * by looking in the row, column, and 3x3 box for a duplicate value.
 * @param: int[][], board, the 2D array board 
 * @param: int, row, the row to check
 * @param: int, col, the column to check
 * @param: int, value, the value we will look for duplicates of
 * @returns: bool, true if the value passes all conditions, false if a duplicate
 * value was found in one of the condition checks
 **********************************************************************************/
bool isValidOption(int board[9][9], int row, int col, int value) {
	return (checkRow(board, row, value) && checkColumn(board, col, value) && 
		checkThreeBox(board, row, col, value));
}


/*********************************************************************************
 * Deterrmins if we are finished based on if the board contains an empty spot.
 * @param: int[][], board, the 2D array board 
 * @returns: bool, true if there are no empty spots, false if there is at least one
 * empty spot on the board
 **********************************************************************************/
bool isFinished(int board[9][9]) {
	for(int row = 0; row < 9; row++){
		for(int col = 0; col < 9; col++){
			if(board[row][col] == 0){
				return false;
			}
		}
	}	
	return true;
}

/**********************************************************************
 *Called when an invalid value is placed, sets specified spot on
 * grid to 0
 *********************************************************************/
void setEmptyCell(int board[9][9], int row, int col) {
	board[row][col] = 0;
}

/*********************************************************************************
 * Prints out the sudoku board.
 * @param: int[][], board, the 2D array board 
 **********************************************************************************/
void printBoard(int board[9][9]) {
	for (int row = 0; row < 9; row++) {
		for(int col = 0; col < 9; col++ ) {
			std::cout << board[row][col] << "     ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

/*********************************************************************************
 * This method calculates a 3x3 square to check for duplicate values.
 * @param: int[][], board, the 2D array board 
 * @param: int, row, the row to check
 * @param: int, col, the column to check
 * @param: int, value, the value to check for duplicates of
 * @returns: bool, true if no duplicte value was found, false if a duplicate value
 * was found
 **********************************************************************************/
bool checkThreeBox(int board[9][9], int row, int col, int value) {

	int minRow, maxRow;
	int minCol, maxCol;
	
	switch(row) {
	   case 0:
	   case 1:
	   case 2:
		minRow = 0;
		maxRow = 2;
		break;
	   case 3:
	   case 4:
	   case 5:
		minRow = 3;
		maxRow = 5;
		break;
	   default:
		minRow = 6;	
		maxRow = 8;
		break;
	}

	switch(col) {
	   case 0:
	   case 1:
           case 2:
		minCol = 0;
		maxCol = 2;
	        break;
	   case 3:
	   case 4:
	   case 5:
		minCol = 3;
		maxCol = 5;
	   	break;
	   default:
		minCol = 6;	
		maxCol = 8;
		break;
	}

	for(int row = minRow; row <= maxRow; row++) {
		for(int col = minCol; col <= maxCol; col++) {
			if(board[row][col] == value) {
				return false;
			}
		}
	}
	return true;
}
