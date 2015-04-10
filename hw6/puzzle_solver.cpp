#include "puzzle_solver.h"
#include <iostream>

using namespace std;
// Constructor (makes a copy of the Board and stores it in b_)
  //  Also takes a PuzzleHeuristic which will score boards
  PuzzleSolver::PuzzleSolver(const Board &b, PuzzleHeuristic* ph): _b(b), _ph(ph)
  {
  	_expansions = 0;
  }

  // Destructor
  PuzzleSolver::~PuzzleSolver()
  {
  	//delete _ph;
  }

  // Run the A* search and builds the solution and tracks
  // the number of expansions
  void PuzzleSolver::run()
  {
  	//original board
  	PuzzleMove* current = new PuzzleMove(&_b);
  	//closed list
	PuzzleMoveScoreComp comp1;
	PuzzleMoveBoardComp comp2;
  	PuzzleMoveSet closed_list(comp2);



	//open list
 	Heap<PuzzleMove*, PuzzleMoveScoreComp> open_list(2, comp1);
  	open_list.push(current);
  	closed_list.insert(current);
  	
  	int addedTiles = 0;
  	while (current->b->solved() == false)
  	{
  		
  		map<int, Board*> potentialMoves = current->b->potentialMoves();
  		map<int, Board*>::iterator it;
  		for (it = potentialMoves.begin(); it!= potentialMoves.end(); ++it)
  		{
  			PuzzleMove* currentPotentialMove = new PuzzleMove(it->first, it->second, current);
			currentPotentialMove->h = _ph->compute(*currentPotentialMove->b);

  			 
  			if (closed_list.find(currentPotentialMove) == closed_list.end())
			{
				open_list.push(currentPotentialMove);
				closed_list.insert(currentPotentialMove);
				_expansions++;
			}

			else
			{
				delete currentPotentialMove;
			}
  		}

  		current = open_list.top();
  		addedTiles++;
  		open_list.pop();
  	}



  	//cout << "addedTiles is: " << addedTiles;
  	
  	while (current->prev != NULL)
  	{
  		_solution.push_front(current->tileMove);

  		current = current->prev;
  	}
  

  	//delete current;
  	PuzzleMoveSet::iterator it2;
  	for (it2 = closed_list.begin(); it2 != closed_list.end(); ++it2)
  	{
  		delete *it2;

  	}


  }


  // Return the solution deque
  std::deque<int> PuzzleSolver::getSolution()
  {
return _solution;

  }

  // Return how many expansions were performed in the search
  int PuzzleSolver::getNumExpansions()
  {


  	return _expansions;
  }