#pragma once
/*
* This class describes what a PuzzleState is.
* The blank_position is for decreasing the time
* to check what tile operator is applicable
*/
#ifndef _PUZZLESTATE_
#define _PUZZLESTATE_
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

class PuzzleState
{
public:
	PuzzleState() { }  // default constructor

	PuzzleState(int n, int m)  //constructor
	{
		tiles.resize(n*m); rows = n; cols = m;
	}
	~PuzzleState() { }   //destructor
	PuzzleState(const PuzzleState & rhs)   // copy constructor
		: rows(rhs.rows), cols(rhs.cols),
		tiles(rhs.tiles),
		blank_position_row(rhs.blank_position_row),
		blank_position_col(rhs.blank_position_col)
	{ }

	bool operator==(const PuzzleState & rhs) const;
	bool operator!=(const PuzzleState & rhs) const;
	const PuzzleState & operator=(const PuzzleState & rhs); //assignment op
	bool isNullState() { return rows == 0; }

	bool canMoveUp();
	bool canMoveDown();
	bool canMoveLeft();
	bool canMoveRight();
	PuzzleState moveBlankUp();
	PuzzleState moveBlankDown();
	PuzzleState moveBlankLeft();
	PuzzleState moveBlankRight();

	void read(istream & in);
	void print(ostream & out);
	static PuzzleState  NullState;


private:
	int rows;
	int cols;
	vector<int> tiles;
	int blank_position_row;
	int blank_position_col;
};
istream & operator >> (istream &  in, PuzzleState & rhs);
//rhs(in);
//return in;
ostream & operator<<(ostream & out, PuzzleState & rhs);
//rhs(out);
//return out;
#endif
