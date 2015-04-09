#include <iostream>
#include <cstdlib>
#include <deque>
#include <sstream>
#include "board.h"
#include "puzzle_heur.h"
#include "puzzle_solver.h"

using namespace std;

int main(int argc, char *argv[])
{
  if(argc < 5){
    cerr << "Usage: ./puzzle size initMoves seed heur" << endl;
    return 1;
  }


  stringstream strm;

  char* dimensionChar = argv[1];
  char* initMovesChar = argv[2];
  char* seedChar = argv[3];
  char* heurChar = argv[4];

  strm << dimensionChar <<" " << initMovesChar << " " << seedChar << " " << heurChar;
  int dimension; 
  int initMoves;
  int seed;
  int heur;

  strm >> dimension >> initMoves >> seed >> heur;

PuzzleHeuristic* comp;
PuzzleHeuristic * comp0 = new PuzzleBFSHeuristic();
PuzzleHeuristic * comp1 = new PuzzleOutOfPlaceHeuristic();
PuzzleHeuristic * comp2 = new PuzzleManhattanHeuristic();


if ( heur ==0)
{
 comp = comp0;
}

else if (heur == 1)
{
	comp = comp1;
}

else if (heur == 2)
{
	comp = comp2;

}

else
{

}

  Board b(dimension, initMoves, seed);

  cout << b;
  cout << "Enter tile number to move or -1 for a cheat: ";


  	int input;
  while (cin >> input)
	{


	if (input ==0)
	{


	}
	else if (input == -1)
	{
		PuzzleSolver* solution = new PuzzleSolver(b, comp);
		solution->run();
		deque<int> answers = solution->getSolution();
		cout << "Try this sequence:" << endl;
		for (unsigned int i=0; i<answers.size(); i++)
		{
			cout << answers[i] << " ";

		}
		cout << endl;
		int numExpansions = solution->getNumExpansions();
		cout << "(Expansions = " << numExpansions << ")" << endl;


	}
	else if (input > 0 && input < dimension*dimension)

	{
		b.move(input);
		cout << b;
		cout << "Enter tile number to move or -1 for a cheat: " << endl;
	}

	else
	{


	}
}
}
