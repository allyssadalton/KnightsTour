/*    @file Knights.cpp   
      @author Allyssa Dalton
      @date 02/02/2025

			@description Completes Knights Tour
*/

#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>  // For hash
#include <iomanip>
#include <stdexcept>
#include "Knights.h"

Knights::Knights(int x, int y):w(x), h(y), board(x * y, EMPTY){};


bool Knights::solve(){
  board = vector<int>(w * h, EMPTY); //empties board so you cant cheat or try to break it
  board.at(XY(0, 0)) = 0; //places knight at top left corner
  if (!solve(board, 0)){
    cout << "Unsolvable" << endl;
    return false;
  }
  else{
    return true;
  }
}

bool Knights::solve(vector<int> &board, unsigned int move){
  // base case
  if (move == (w * h - 1)){ 
    if (completeTour()){cout << "Solved" << endl;}
    else{cout << "Uncompleted" << endl;}
    print();
    return true;
  }

  unsigned int x = 0;
  unsigned int y = 0;
  bool knightPlaced = false; //used to double check if knights place exists
  for (unsigned int j = 0; j < h; j++){
    for (unsigned int i = 0; i < w; i++){
      if (board.at(XY(i, j)) == static_cast<int>(move)){
        x = i;
        y = j;
        knightPlaced = true;
        break;
      }
    }
  }
  if (!knightPlaced){
    return false;
  }//returns false if there is no knight

  vector<pair<int, int>> moves ={{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}}; //all possible moves for knight
  for (auto [dx, dy] : moves){  //iterates through the vector of pairs, shout out to ChatGPT for this line
    int newX = x + dx;
    int newY = y + dy;

    // Ensures newX & newY is in the board and empty
    if (newX >= 0 && newX < static_cast<int>(w) && newY >= 0 && newY < static_cast<int>(h) && board.at(XY(newX, newY)) == EMPTY){
      board.at(XY(newX, newY)) = static_cast<int>(move) + 1; //gives the spot the number of what move it was touched by
      if (solve(board, move + 1)){return true;} //recursion hehe
      board.at(XY(newX, newY)) = EMPTY; //undoes the move just done
    }
  }
  return false;
}
    
bool Knights::completeTour(){
  vector<unsigned int> moveTracker(w * h, 0); //vector to hold all of the moves on the board
  for (unsigned int i = 0; i < w; i++){
    for (unsigned int j = 0; j < h; j++){
      if (board.at(XY(i, j)) >= 0){
        if (moveTracker[board.at(XY(i, j))] != 0){return false;} //checks if 1 number exists twice on the board
        else{moveTracker[board.at(XY(i, j))] = board.at(XY(i, j));} //puts the moves on the board into their spot in the vector
      }
    }
  }
  for (unsigned index = 0; index < (w * h); index++){
    if (moveTracker[index] != index){return false;} //makes sure every index has the value it should 
  }
 
  vector<pair<int, int>> moves ={{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}}; //all possible moves for knight
  unsigned int x = 0, y = 0;
  for (unsigned k = 0; k < w * h - 1; k++) {
      bool knightPath = false;
      for (auto [dx, dy] : moves) {
        int newX = x + dx;
        int newY = y + dy;
        if (newX >= 0 && newX < static_cast<int>(w) && newY >= 0 && newY < static_cast<int>(h) &&
          board.at(XY(newX, newY)) == static_cast<int>(k) + 1) {
          x = newX;
          y = newY;
          knightPath = true;
          break;
        }
      }
    if (!knightPath){return false;} // If no valid knight move exists, return false
  }
  return true;
}

void Knights::print(){
  for (unsigned int j = 0; j < h; j++){
    for (unsigned int i = 0; i < w; i++){
      if (board.at(XY(i, j)) != EMPTY){
        if (board.at(XY(i, j)) < 10){cout << "  " << board.at(XY(i, j)) << "|"; }
        else if (board.at(XY(i, j)) > 9){cout << " " << board.at(XY(i, j)) << "|"; } 
      }
      else{cout << "   |";} 
    }
    cout << endl;
  }
}

int& Knights::at(unsigned x, unsigned y){
  return board.at(XY(x, y));
}

unsigned Knights::XY(unsigned x, unsigned y){
  if(x >= w)throw runtime_error("x too big");
  if(y >= h)throw runtime_error("y too big"); 

  return x + y * w;
}

tuple<unsigned, unsigned> Knights::toXY(unsigned i){
  if(i >= board.size())throw runtime_error("invalid index");
  return {i % w, i / w};
}




