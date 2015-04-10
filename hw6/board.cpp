#include <iostream>
#include <iomanip>
#include <map>
#include <cmath>
#include <cstdlib>
#include <stdexcept>
#include "board.h"
using namespace std;


Board::Board(int dim, int numInitMoves, int seed )
{
  _size = dim*dim;
  _tiles = new int[_size];
  srand(seed);
  for(int i=0; i < _size; i++){
    _tiles[i] = i;
  }
  int blankLoc = 0;
  while(numInitMoves > 0){
    int r = rand()%4;
    int randNeighbor = -1;
    if(r == 0){
      int n = blankLoc - dim;
      if(n >= 0){
	randNeighbor = n;
      }
    }
    else if(r == 1){
      int w = blankLoc - 1;
      if(blankLoc % dim != 0){
	randNeighbor = w;
      }
    }
    else if(r == 2){
      int s = blankLoc + dim;
      if(s  < _size){
	randNeighbor = s;
      }
    }
    else {
      int e = blankLoc + 1;
      if(blankLoc % dim != dim-1){
	randNeighbor = e;
      }
    }
    if(randNeighbor > -1){
      _tiles[blankLoc] = _tiles[randNeighbor];
      _tiles[randNeighbor] = 0;
      blankLoc = randNeighbor;
      numInitMoves--;
    }
  }
}


Board::~Board()
{


delete[] _tiles;

}
Board::Board( const Board &b)
{

_tiles = new int [b._size];
_size = b._size;

for (int i=0; i< b._size; i++)
  {
    _tiles[i] = b._tiles[i];

  }

}

Board& Board::operator=(const Board& b)
{

  if (this == &b)
  {
    return *this;

  }
  if (_tiles)
  {
    delete _tiles;

  }

  _tiles = new int[b._size];
  _size = b._size;
  for (int i=0; i < b._size; i++)
  {
  _tiles[i] = b._tiles[i];
  }

return *this;


}


void Board::move(int tile)
{
  int side_dim = dim();
  int tr, tc, br, bc;

  // find tile row and column
  int i=-1;
  while(_tiles[++i] != tile);

  tr = i / side_dim; 
  tc = i % side_dim;

  // find blank row and column
  int j=-1;
  while(_tiles[++j] != 0);

  br = j / side_dim;
  bc = j % side_dim;

  if( abs(static_cast<double>(tr-br)) + abs(static_cast<double>(tc-bc)) != 1){
    cout << "Invalid move of tile " << tile << " at ";
    cout << tr << "," << tc << " and blank spot at ";
    cout << br << "," << bc << endl;
    return;
  }
  // Swap tile and blank spot
  _tiles[j] = tile;
  _tiles[i] = 0;
}

// Generate new boards representing all the potential moves of tiles into 
// the current blank tile location. The returned map should have
// the key as the tile moved and the value as a new Board object with the
// configuration reflecting the move of that tile into the blank spot
map<int, Board*> Board::potentialMoves() const
{
   map<int, Board*> boardMap; //map to be returned

 // boardMap.clear();



  
int blankSpace = 0;
  for (int i=0; i < _size; i++)
  {

    if (_tiles[i] == 0)
    {
      blankSpace = i; //taylor Swift

    }
  }

  int dimension = dim(); //dimension of the board




//South Tile
if (blankSpace < _size - dimension)
  {
  Board* south = new Board(*this);
  int numberToMove = south->_tiles[blankSpace + dimension];
  if (numberToMove != 0)
    {
    south->move(numberToMove);
    boardMap.insert(make_pair(numberToMove, south));
    }
  }

 

//East Tile
if (blankSpace % dimension != dimension-1)
  {
  Board* east = new Board(*this);
  int numberToMove = east->_tiles[blankSpace + 1];
  if (numberToMove != 0)
    {
    east->move(numberToMove);
    boardMap.insert(make_pair(numberToMove, east)); 
    }
  }
 
//West Tile
if (blankSpace % dimension != 0)
  {
  Board* west = new Board(*this); //west
  int numberToMove = west->_tiles[blankSpace - 1];
  if (numberToMove != 0)
    {
    west->move(numberToMove);
    boardMap.insert(make_pair(numberToMove, west));
    } 
  }


//North Tile
if (blankSpace > dimension-1)
  {
  Board* north = new Board(*this); 
  int numberToMove = north->_tiles[blankSpace - dimension];
  if (numberToMove != 0) 
    { 
    north->move(numberToMove);
    boardMap.insert(make_pair(numberToMove, north));
    }
  }
  return boardMap;
}

std::ostream& operator<<(std::ostream &os, const Board &b)
{
  int dimension = b.dim(); //dimension of the board
  b.printRowBanner(os);
  for (int i=0; i< (b._size / dimension); i++)
  {

    os << "|";
    for (int j=0; j< dimension; j++)
    {
     if (b[dimension*i + j] != 0) 
      {
        if (b[dimension*i + j] >= 10)
        {     
            os << b[dimension*i + j] << "|";
          }
        else
        {
        os << " " << b[dimension*i + j] << "|";
        }
      } 
     else 
      {
        os << "  " << "|";
      }
    }
    os << "\n";
    b.printRowBanner(os);
    


  }


return os;
}

bool Board::operator<(const Board& rhs) const
{


  for (int i=0; i < _size; i++)
  {
    if (_tiles[i] < rhs._tiles[i])
    {
      return true;

    }
    if(_tiles[i] > rhs._tiles[i])
    {
      return false;
    }

  }

return false;
}




const int& Board::operator[](int loc) const 
{ 
  return _tiles[loc]; 
}

int Board::size() const 
{ 
  return _size; 
}

int Board::dim() const
{
  return static_cast<int>(sqrt(_size));
}

void Board::printRowBanner(ostream& os) const
{
  int side_dim = dim();
  if(side_dim == 0) return;
  os << '+';
  for(int i=0; i < side_dim; i++){
    os << "--+";
  }
  os << endl;
}


bool Board::solved() const
{
bool ok = true; //checks that the board is fine
for (int i=1; i < _size; i++)
{
  //if each slot in the array is incremented by 1
  if (_tiles[i] != _tiles[i-1]+1) 

  {
    ok = false;
  }


}

return ok;

}