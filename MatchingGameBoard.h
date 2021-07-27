#pragma once
class MatchingGameBoard
{
public:
	MatchingGameBoard(); //Contructor
	~MatchingGameBoard(); //Decontructor

	void SetUpBoard();
	void DeleteBoard(); // removes board to free memory

	COLORREF GetBoardSpace(int row, int col); //Gets the color at a particular location

	//Functions to get the board size info
	int GetWidth() const { return _Width; }
	int GetHeight() const { return _Height; }
	int GetColumns() const { return _Columns; }
	int GetRows() const { return _Rows; }


private:
	void CreateBoard();

	COLORREF _arrayColors[4];

	int** _arrayBoard; // 2d array pointer
	int _Width;
	int _Height;
	int _Columns;
	int _Rows;

};

