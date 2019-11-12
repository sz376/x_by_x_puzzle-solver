#pragma once
#ifndef _PUZZLEMOVE_
#define _PUZZLEMOVE_

#include "PuzzleState.h"
using namespace std;
enum MoveType { down, left, right, up, nullMove };
class PuzzleMove
{
public:
	PuzzleMove() { }
	PuzzleMove(PuzzleState s, PuzzleState p, MoveType m) : state(s), parent(p), move(m)
	{ }
	PuzzleState & getState()
	{
		return state;
	}
	PuzzleState & getParent()
	{
		return parent;
	}
	MoveType getMoveName()
	{
		return move;
	}
private:
	PuzzleState state;
	PuzzleState parent;
	MoveType move;
};
#endif

