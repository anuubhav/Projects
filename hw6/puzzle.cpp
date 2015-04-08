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

  Board* initial = new Board(dimension, initMoves, seed);

  cout << *initial;

  return 0;
}
