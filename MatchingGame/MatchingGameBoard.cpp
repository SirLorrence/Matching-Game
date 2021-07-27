#include "pch.h"
#include "MatchingGameBoard.h"

#pragma region Contructors
//Declares the size and the color that will be on the board 
MatchingGameBoard::MatchingGameBoard() :_arrayBoard(NULL), _Columns(15), _Rows(15), _Height(35), _Width(35) {
	_arrayColors[0] = RGB(0, 0, 0);
	_arrayColors[1] = RGB(255, 0, 0);
	_arrayColors[2] = RGB(255, 255, 64);
	_arrayColors[3] = RGB(0, 0, 255);
}


MatchingGameBoard::~MatchingGameBoard() {
	DeleteBoard();
}
#pragma endregion

#pragma region Set Up
void MatchingGameBoard::SetUpBoard() {
	if (_arrayBoard == NULL)
		CreateBoard();

	//Set each square randomly to a different color
	for (int row = 0; row < _Rows; row++) {
		for (int col = 0; col < _Columns; col++) {
			_arrayBoard[row][col] = (std::rand() % 3) + 1;
		}
	}

}


COLORREF MatchingGameBoard::GetBoardSpace(int row, int col) {
	//check if its in the bounds of the array
	if (row < 0 || row >= _Rows || col < 0 || col >= _Columns)
		return _arrayColors[0];
	//then return the color at the coordinate point
	return _arrayColors[_arrayBoard[row][col]];
}
#pragma endregion

#pragma region Board Management
void MatchingGameBoard::CreateBoard() {
	//Check if theres a board, if so delete it
	if (_arrayBoard != NULL)
		DeleteBoard();
	_arrayBoard = new int* [_Rows]; // create the array of rows
	for (int row = 0; row < _Rows; row++) {
		_arrayBoard[row] = new int[_Columns]; //within each row, create a columns in the
		for (int col = 0; col < _Columns; col++) {
			_arrayBoard[row][col] = 0; // set the to empty be default
		}
	}
}


void MatchingGameBoard::DeleteBoard() {
	if (_arrayBoard != NULL) {
		for (int row = 0; row < _Rows; row++) {
			//deletes each row first
			if (_arrayBoard[row] != NULL) {
				delete[] _arrayBoard[row];
				_arrayBoard[row] = NULL;
			}
		}
		//then deletes the final row
		delete[] _arrayBoard;
		_arrayBoard = NULL;
	}
}
#pragma endregion