#include <string>
#include <iostream>

/**
 *This file houses the back tracking algorithm to 
 *sort and creat a new sudoku board
 *
 *@author Nabeel Vali
 */

bool isFinished(int board[9][9]);
void printBoard(int board[9][9]);
void solveBoard(int board[9][9]);
std::string findEmptyLocation(int board[9][9]);

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



	if(isFinished(board)) {
		//printBoard(board);
	} else {
		solveBoard(board);
	}


}




void solveBoard(int board[9][9]){

	if(isFinished(board)) {
	//	printBoard(board);
	} else {
		std::string emptyLocation = findEmptyLocation(board);
		//std::cout << emptyLocation.at(0) << std::endl;
		//std::cout << emptyLocation.at(1) << std::endl;
		char r = emptyLocation.at(0);
		char c = emptyLocation.at(1);
		int row = r - '0';
		int col = c - '0';
		std::cout << row + " " + col << std::endl;
	}

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

std::string findEmptyLocation(int board[9][9]) {
		
	std::string emptyLocation = "";
	
	for(int row = 0; row < 9; row++) {
		for(int col = 0; col < 9; col++) {
			if(board[row][col] == 0) {
				emptyLocation = std::to_string(row) 
				+ std::to_string(col);
				//std::cout << "empty cell" + emptyLocation << std::endl;
				return emptyLocation;
			}
		}
	}
}


