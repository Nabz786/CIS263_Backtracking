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
//		printBoard(board);
	} else {
		solveBoard(board);
	}
}

bool checkSquare(int board[9][9], int row, int col, int value){
//	int temp [9];
//	for (int i = 0; i < 9; i = i + 3){
//		for(int j = 0; j < 9; j = j + 3){
//		//	temp [9] == {board[i][j], board[i][j+ 1]};
//		}
//	}
//	
//	return true;

//Need to finish this method, try to find a way using the parameters that get passed in	

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
	//	printBoard(board);
	} else {
		std::vector<int> emptyLocation = findEmptyLocation(board);
		int eRow = emptyLocation.at(0);
		int eCol = emptyLocation.at(1);	
		emptyLocation.clear();		

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
				emptyLocation.push_back(row);
				emptyLocation.push_back(col);
				return emptyLocation;
			}
		}
	}
}


