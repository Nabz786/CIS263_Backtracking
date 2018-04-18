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
//bool checkThreeBox(int board[9][9], int row, int col, int value);
void backtracking (int board[9][9]);
std::vector<int> findEmptyLocation(int board[9][9]);


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


	backtracking(board);
}

void backtracking (int board[9][9]){


	if(isFinished(board)) {
		printBoard(board);
	} else {
		solveBoard(board);
	}
}

bool checkSquare(int board[9][9], int row, int col, int value){
int temp[9];
	for (int i = (row/3); i < (i + 3); i++){
		for (int j = (col/3); j < (j + 3); j++){
			if(board[i][j] == value){
					return false;
				} 
			}
		}
	}
		
	return true;
}

bool checkColumn(int board[9][9], int col, int value){

	for(int i = 1; i <=9; i++) {
		if (board[i][col] == value) {
			return false;
		}
	}
	return true;
}



bool checkRow(int board[9][9], int row, int value){

	for(int i = 1; i <= 9; i++) {
		if(board[row][i] == value) {
			return false;
		}
	}
	return true;
}


bool solveBoard(int board[9][9]){

	if(isFinished(board)) {
		printBoard(board);
		std::cout << "Finished" << std::endl;
	} else {
		printBoard(board);
//		std::cout << "here" << std::endl;
	//	std::cout << findEmptyLocation(board).at(0) << std::endl;
		int eRow = findEmptyLocation(board).at(0);
		int eCol = findEmptyLocation(board).at(1);
//		std::cout << eRow << std::endl;	
//		std::cout << findEmptyLocation(board).at(0) << std::endl;
//		std::cout << findEmptyLocation(board).at(1) << std::endl;
		for(int i = 1; i <= 9; i++){		
			if(isValidOption(board, eRow, eCol, i)) {
				board[eRow][eCol] = i;
				
				if(solveBoard(board)) {
					std::cout << "here" << std::endl;
					return true;
				} else {
					board[eRow][eCol] = 0;
				}
			}
		}
		return false;
	}
}

bool isValidOption(int board[9][9], int row, int col, int value) {
	return (checkRow(board, row, value) && checkColumn(board, col, value) && 
		checkSquare(board, row, col, value));
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

std::vector<int> findEmptyLocation(int board[9][9]) {

	std::vector<int> emptyLocation;	
		
	for(int row = 0; row < 9; row++) {
		for(int col = 0; col < 9; col++) {
			if(board[row][col] == 0) {
		//		std::cout << "herenow" << std::endl;
		//		std::cout << row  << std::endl;
		//		std::cout << col << std::endl;
				emptyLocation.push_back(row);
				emptyLocation.push_back(col);
				return emptyLocation;
			}
		}
	}
}

void printBoard(int board[9][9]) {

	for (int row = 0; row <= 9; row++) {
		for(int col = 0; col <= 9; col++ ) {
			std::cout << board[row][col] << "   ";
			std::cout << std::endl;
		}


	}	
	std::cout << std::endl;
}

//bool checkThreeBox(int board[9][9], int row, int col, int value) {
//
//	int minRow, maxRow;
//	int minCol, maxCol;
//
//	if(row == 1 || row == 2 || row == 3) {
//		minRow = 1;
//		maxRow = 3;
//	} else if (row == 4 || row == 5 || row == 6) {
//		minRow = 4;
//		maxRow = 6;
//	} else {
//		minRow = 7;
//		maxRow = 9;
//	}
//
//	if(col == 1 || col == 2 || col == 3) {
//		minCol = 1;
//		maxCol = 3;
//	} else if (col == 4 || col == 5 || col == 6) {
//		minCol = 4;
//		maxCol = 6;
//	} else {
//		minCol = 7;
//		maxCol = 9;
//	}
//
//	for(int row = minRow; row <= maxRow; row++) {
//		for(int col = minCol; col <= maxCol; col++) {
//			if(board[row][col] == value) {
//				return false;
//			}
//		}
//	}
//	return true;
//}

