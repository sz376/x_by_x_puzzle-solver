#include "PuzzleState.h"
#include "PuzzleMove.h"

using namespace std;

bool PuzzleState::operator==(const PuzzleState &rhs) const
{
	return this->tiles == rhs.tiles;
}
bool PuzzleState::operator!=(const PuzzleState &rhs) const
{
	return !(*this == rhs);
}
const PuzzleState & PuzzleState::operator= (const PuzzleState &rhs)
{
	this->blank_position_col = rhs.blank_position_col;
	this->blank_position_row = rhs.blank_position_row;
	this->rows = rhs.rows;
	this->cols = rhs.cols;
	this->tiles = rhs.tiles;

	return *this;
}
bool PuzzleState::canMoveUp()
{
	if (blank_position_row - 1 >= 0)
		return true;
	return false;
}
bool PuzzleState::canMoveDown()
{
	if (blank_position_row + 1 < rows)
		return true;
	return false;
}
bool PuzzleState::canMoveLeft()
{
	if (blank_position_col - 1 >= 0)
		return true;
	return false;
}
bool PuzzleState::canMoveRight()
{
	if (blank_position_col + 1 < cols)
		return true;
	return false;
}
PuzzleState PuzzleState::moveBlankUp()
{
	PuzzleState s(*this);
	if (canMoveUp())
	{
		swap(s.tiles[blank_position_row * cols + blank_position_col],
			s.tiles[(blank_position_row - 1) * cols + blank_position_col]);
		s.blank_position_row = blank_position_row - 1;

	}
	return s;

}
PuzzleState PuzzleState::moveBlankDown()
{
	PuzzleState s(*this);
	if (canMoveDown())
	{
		swap(s.tiles[blank_position_row * cols + blank_position_col],
			s.tiles[(blank_position_row + 1) * cols + blank_position_col]);
		s.blank_position_row = blank_position_row + 1;
	}
	return s;

}
PuzzleState PuzzleState::moveBlankLeft()
{
	PuzzleState s(*this);
	if (canMoveLeft())
	{
		swap(s.tiles[blank_position_row * cols + blank_position_col],
			s.tiles[blank_position_row * cols + blank_position_col - 1]);
		s.blank_position_col = blank_position_col - 1;
	}
	return s;
}
PuzzleState PuzzleState::moveBlankRight()
{
	PuzzleState s(*this);
	if (canMoveRight())
	{
		swap(s.tiles[blank_position_row * cols + blank_position_col],
			s.tiles[blank_position_row * cols + blank_position_col + 1]);
		s.blank_position_col = blank_position_col + 1;
	}
	return s;

}
void PuzzleState::read(istream &in = cin)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			in >> tiles[i * cols + j];
			if (tiles[i * cols + j] == 0)
			{
				blank_position_row = i;
				blank_position_col = j;
			}
		}
	}
}
void PuzzleState::print(ostream &out = cout)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			out << tiles[i * cols + j] << " ";
		}
		out << endl;
	}
}

istream &operator >> (istream &in, PuzzleState &rhs)
{
	rhs.read(in);
	return in;
}
ostream &operator << (ostream &out, PuzzleState &rhs)
{
	rhs.print(out);
	return out;
}
