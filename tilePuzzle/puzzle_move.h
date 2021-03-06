#ifndef PUZZLEMOVE_H
#define PUZZLEMOVE_H
#include "board.h"

using namespace std;

struct PuzzleMove
{
  // Data members can be public
  int tileMove;  // tile moved to reach the Board b
  Board *b;      // Pointer to a board representing the updated state
  int g;         // distance from the start board
  int h;         // heuristic distance to the goal
  PuzzleMove *prev;  // Pointer to parent PuzzleMove


  // Constructor for starting Board (i.e. initial move)
  PuzzleMove(Board* board);

  // Constructor for subsequent search boards 
  // (i.e. those returned by Board::potentialMoves() )
  PuzzleMove(int tile, Board* board, PuzzleMove *parent);

  // Destructor
  ~PuzzleMove();

};


struct PuzzleMoveScoreComp
{
  bool operator()(const PuzzleMove *m1, const PuzzleMove *m2) const
  {
    // Add code to check if m1's f-score is less than m2's
    // If both have the same f-score, break ties by using 
    // the checking if m1's h-score is less than m2's

    int m1FScore = m1->g + m1->h;
    int m2FScore = m2->g + m2->h;

    if (m1FScore < m2FScore)
    {
      return true;

    }
    else if (m1FScore > m2FScore)
    {
      return false;

    }
    else 
    {
      if (m1->h < m2->h)
      {
        return true;
      }
      else 
      {
        return false;
      }

    }


  }
};

struct PuzzleMoveBoardComp
{
  bool operator()(const PuzzleMove *m1, const PuzzleMove *m2) const
  {
    // Add code to check if m1's board is "less-than" m2's board by 
    // using the Board class' operator<()

    if (*(m1->b) < *(m2->b))
      {
        return true;
      }
    
    else 
      {
        return false;
      }

  }
};

#endif
