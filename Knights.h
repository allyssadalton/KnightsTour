#ifndef KNIGHTS_H
#define KNIGHTS_H  

/*    @file Knights.h   
       @author Allyssa Dalton
      @date 02/02/2025

			@description Header file for Knights.cpp
*/
#include <string>
#include <vector>
#include <array>
#include <unordered_set>

#define EMPTY -1  // Set value for an empty spot.
#define KNIGHT 1

using namespace std;

class Knights{
  public:
  // Set up a board with the given width and height.
  Knights(int x, int y);

  // Attempt to solve the board of the predefined width and height.
  // This should print the final solution if found.
  bool solve();
  bool solve(vector<int> &board, unsigned int move);

  // private: // Making public for testing purposes
  unsigned w, h;
  vector<int> board;
  unsigned int move;

  // Return true if the given board is a complete knights tour.
  bool completeTour();

  // Print the given board, with EMPTY printed as 3 spaces.
  void print();

  // Returns a reference to the position in the board at x,y
  int& at(unsigned x, unsigned y);

  // Helper function for converting x/y coordinates to a linear index.
  unsigned XY(unsigned x, unsigned y);

  // Helper function to convert linear index to x/y coordinates
  tuple<unsigned, unsigned> toXY(unsigned i);
  
};


  
#endif