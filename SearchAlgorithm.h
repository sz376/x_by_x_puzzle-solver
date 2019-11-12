#pragma once
#pragma once
#include "PuzzleState.h"
#include "PuzzleMove.h"


bool isMember(PuzzleState s, list<PuzzleMove> &t)
{

	list<PuzzleMove>::iterator itr;
	for (itr = t.begin(); itr != t.end(); itr++)
	{
		if ((*itr).getState() == s)
		{
			return true;
		}
	}
	return false;
}
// findNextParent
list<PuzzleMove>::const_iterator & findNextParent(PuzzleState & state,
	list<PuzzleMove>::const_iterator & from,
	list<PuzzleMove> aMoveList)
{
	PuzzleMove aMove;
	list<PuzzleMove>::const_iterator & itr = from;
	for (itr = from; itr != aMoveList.end(); itr++)
	{
		aMove = *itr;
		if (state == aMove.getState()) break;
	}
	return itr;
}
PuzzleState PuzzleState::NullState(0, 0);

bool find_solution(PuzzleState start, PuzzleState goal, list<PuzzleMove> &solution)
{
	PuzzleState currentState;
	PuzzleState childState;
	PuzzleState parentState;
	PuzzleMove currentMove;
	list<PuzzleMove> open;
	list<PuzzleMove> closed;
	list<PuzzleMove>::const_iterator lastFoundPosition;
	list<PuzzleMove>::iterator itr;


	open.push_back(PuzzleMove(start, PuzzleState::NullState, nullMove));

	while (!open.empty())
	{
		currentMove = open.front();
		open.pop_front();
		currentState = currentMove.getState();


		if (currentState == goal)
		{
			lastFoundPosition = closed.begin();
			parentState = currentMove.getParent();
			cout << currentState << endl;
			cout << endl;
			break;

			while (parentState != PuzzleState::NullState)
			{
				solution.push_front(currentMove);
				currentState = parentState;
				lastFoundPosition = findNextParent(currentState, lastFoundPosition, closed);
				currentMove = *lastFoundPosition;
				parentState = currentMove.getParent();

			}
			return true;
		}
		else
		{
			closed.push_front(currentMove);

			if (currentState.canMoveDown())
			{

				childState = currentState.moveBlankDown();

				if (!isMember(childState, open) && !isMember(childState, closed))
				{

					open.push_front(PuzzleMove(childState, currentState, MoveType::down)); //dfs
					cout << currentState;
					cout << endl;

				}

			}
			if (currentState.canMoveLeft())
			{

				childState = currentState.moveBlankLeft();


				if (!isMember(childState, open) && !isMember(childState, closed))
				{
					open.push_front(PuzzleMove(childState, currentState, MoveType::left));
					cout << currentState;
					cout << endl;
				}

			}
			if (currentState.canMoveUp())
			{

				childState = currentState.moveBlankUp();

				if (!isMember(childState, open) && !isMember(childState, closed))
				{
					open.push_front(PuzzleMove(childState, currentState, MoveType::up));
					cout << currentState;
					cout << endl;
				}

			}
			if (currentState.canMoveRight())
			{
				childState = currentState.moveBlankRight();
				if (!isMember(childState, open) && !isMember(childState, closed))
				{
					open.push_front(PuzzleMove(childState, currentState, MoveType::right));
					cout << currentState;
					cout << endl;
				}

			}
		}	// end else add node to explored list and expand node
	} // end while
	return false;
}