#include "SearchAlgorithm.h"
using namespace std;




int main()
{
	int n = 0;
	int searchtype = 0;

	cout << " Enter size of tile puzzle: ";
	cin >> n;

	PuzzleState start(n, n);
	PuzzleState goal(n, n);
	list<PuzzleMove> sol;
	list<PuzzleMove>::iterator itr;

	cout << " Enter start state row by row: " << endl;
	cin >> start;

	cout << " Enter Goal state row by row: " << endl;
	cin >> goal;

	cout << "Solution: " << endl;
	cout << endl;
	while (find_solution(start, goal, sol))
	{
		for (itr = sol.begin(); itr != sol.end(); itr++)
		{
			if ((*itr).getMoveName() == MoveType::up)
			{
				cout << " Up" << endl << endl;
				cout << (*itr).getState();
				cout << endl;
			}
			if ((*itr).getMoveName() == MoveType::down)
			{
				cout << " Down" << endl << endl;
				cout << (*itr).getState();
				cout << endl;
			}
			if ((*itr).getMoveName() == MoveType::left)
			{
				cout << " Left" << endl << endl;
				cout << (*itr).getState();
				cout << endl;
			}
			if ((*itr).getMoveName() == MoveType::right)
			{
				cout << " Right" << endl << endl;
				cout << (*itr).getState();
				cout << endl;
			}
		}
	}


	cout << endl;
	return 0;
}