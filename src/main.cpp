#include <string>
#include <iostream>
#include <vector>
/**********************************************************************************
 *This file houses the back tracking algorithm to sort and creat a new sudoku board
 *@version Winter 2018
 *@author Nabeel Vali, Runquan Ye
 *********************************************************************************/

bool isFinished(int board[9][9]);
void printBoard(int board[9][9]);
bool solveBoard(int board[9][9]);
bool checkSquare(int board[9][9], int row, int col, int value);
bool checkRow(int board[9][9], int row,  int value);
bool checkColumn(int board[9][9], int col, int value);
bool isValidOption(int board[9][9], int row, int col, int value);
bool checkThreeBox(int board[9][9], int row, int col, int value);

//bool checkThreeBox(int board[9][9], int row, int col, int value);
void backtracking (int board[9][9]);


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

//bool checkSquare(int board[9][9], int row, int col, int value){
//int temp[9];
//	for (int i = (row/3); i < (i + 3); i++){
//		for (int j = (col/3); j < (j + 3); j++){
//			if(board[i][j] == value){
//					return false;
//				} 
//			}
//		}
//	}
//		
//	return true;
//}

bool checkColumn(int board[9][9], int col, int value){

	for(int i = 0; i <9; i++) {
		if (board[i][col] == value) {
			return false;
		}
	}
	return true;
}



bool checkRow(int board[9][9], int row, int value){

	for(int i = 0; i < 9; i++) {
		if(board[row][i] == value) {
			return false;
		}
	}
	return true;
}


bool solveBoard(int board[9][9]){
//	printBoard(board);
	
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
					board[eRow][eCol] = 0;
				}
			}
		}
//		std::cout << "here12231" << std::endl;
		return false;
	}
}

bool isValidOption(int board[9][9], int row, int col, int value) {
	return (checkRow(board, row, value) && checkColumn(board, col, value) && 
		checkThreeBox(board, row, col, value));
}

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

void printBoard(int board[9][9]) {


	for (int row = 0; row < 9; row++) {
		for(int col = 0; col < 9; col++ ) {
			std::cout << board[row][col] << "     ";
		}
		std::cout << std::endl;
	}

	
	std::cout << std::endl;
}

bool checkThreeBox(int board[9][9], int row, int col, int value) {

	int minRow, maxRow;
	int minCol, maxCol;

	if(row == 0 || row == 1 || row == 2) {
		minRow = 0;
		maxRow = 2;
	} else if (row == 3 || row == 4 || row == 5) {
		minRow = 3;
		maxRow = 5;
	} else {
		minRow = 6;
		maxRow = 8;
	}

	if(col == 0 || col == 1 || col == 2) {
		minCol = 0;
		maxCol = 2;
	} else if (col == 3 || col == 4 || col == 5) {
		minCol = 3;
		maxCol = 5;
	} else {
		minCol = 6;
		maxCol = 8;
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
