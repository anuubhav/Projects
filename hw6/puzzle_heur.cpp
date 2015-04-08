#include "puzzle_heur.h"
#include <iostream>
#include <cmath>

using namespace std;

int PuzzleManhattanHeuristic::compute(const Board& b)
{
	int dim = b.dim();
	int numTiles = dim * dim -1 
	int manhattanDistance = 0;
	for (int i=0; i < numTiles; i++)
		{
			int currentRow = i/dim;
			int currentCol = i%dim;
			int desiredRow = tiles[i]/dim;
			int desiredCol = tiles[i]%dim;
			manhattanDistance += (abs(currentRow - desiredRow) + abs(currentCol - 
			desiredCol));

		}

	return manhattanDistance;
}

int PuzzleOutOfPlaceHeuristic::compute(const Board& b)
{
	int dim = b.dim();
	int numTiles = dim * dim -1 
	int numTilesOutOfPlace = 0;
	for (int i=0; i < numTiles; i++)
		{
			if (b._tiles[i] != i+1)
			{
				numTilesOutOfPlace++:

			}

		}

	return numTilesOutOfPlace;
}

int PuzzleBFSHeuristic::compute(const Board& b)
{

	return 0;

}