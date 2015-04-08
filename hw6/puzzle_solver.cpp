#include "puzzle_solver.h"
#include <iostream>

using namespace std;
// Constructor (makes a copy of the Board and stores it in b_)
  //  Also takes a PuzzleHeuristic which will score boards
  PuzzleSolver::PuzzleSolver(const Board &b, PuzzleHeuristic* ph): _b(b), _ph(ph)
  {

  }

  // Destructor
  PuzzleSolver::~PuzzleSolver()
  {

  }

  // Run the A* search and builds the solution and tracks
  // the number of expansions
  void PuzzleSolver::run()
  {

  	PuzzleMove* current = new PuzzleMove(&_b);
  	//closed list
	PuzzleMoveScoreComp comp1;
  	 PuzzleMoveSet closed_list;



	//open list
 	Heap<PuzzleMove*, PuzzleMoveScoreComp> open_list(4, comp1);
  	open_list.push(current);
  	closed_list.insert(current);

  	while (_b.solved() == false)
  	{
  		map<int, Board*> potentialMoves =  current->b->potentialMoves();
  		map<int, Board*>::iterator it;
  		for (it = potentialMoves.begin(); it!= potentialMoves.end(); ++it)
  		{
  			PuzzleMove* currentPotentialMove = new PuzzleMove(it->first, it->second, current);
  			 PuzzleMoveSet::iterator it_two;
  			it_two = closed_list.find(currentPotentialMove);
  			if (it_two == closed_list.end())
  			{
  				open_list.push(currentPotentialMove);

  			} 

  		}

  		current = open_list.top();
  		open_list.pop();

  	}

  	while (current->prev != NULL)
  	{
  		_solution.push_front(current->tileMove);
  		current = current->prev;
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


  	return 0;
  }