#This folder contains the implementation of the sliding tile puzzle game in C++

It is implemented using multiple heuristics to run the A* search.
Heuristic 0- Manhattan Distance
Heuristic 1- Heuristic determined by number of pieces out of place
Heuristic 2- Breadth First Search

Usage: 
./puzzle size initMoves seed heur

size = dimensions of board. ex: "3" creates a 3x3 board
initMoves = number of moves already performed on the board prior to starting
seed = number that random number generator is seeded with
heur = desired heuristic (0/1/2)
