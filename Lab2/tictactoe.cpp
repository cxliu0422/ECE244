//
//  main.cpp
//  TicTacTo
//
//  Created by Tarek Abdelrahman on 2019-06-07.
//  Modified by Tarek Abdelrahman on 2020-09-17.
//  Copyright © 2019-2020 Tarek Abdelrahman. All rights reserved.
//
//  Permission is hereby granted to use this code in ECE244 at
//  the University of Toronto. It is prohibited to distribute
//  this code, either publicly or to third parties.
//
//  ECE244 Student: Complete the skeletal code of the main function in this file

#include <iostream>
#include <string>
using namespace std;

#include "GameState.h"
#include "globals.h"

// Function prototype for playMove
void playMove(GameState &);

// The main function
int main() {

  /**********************************************************************************/
  /* Create an initialized game state object */
  /**********************************************************************************/
  GameState game_state;

  // Read two integers from the user that represent the row and column
  // the player would like to place an X or an O in
  // You can assume there will be no formatting errors in the input

  int row;
  int col;
  while (!game_state.get_gameOver()) {
    cout << "Enter row and column of a grid cell: ";
    cin >> row >> col;

    // Check that the read row and column values are valid grid coordinates
    if ((row < 0) || (row > 2) || (col < 0) || (col > 2)) {
      cout << "Invalid board coordinates " << row << " " << col << endl << endl;
      continue;
    }
    game_state.set_selectedRow(row);
    game_state.set_selectedColumn(col);
    // cout<<game_state.get_selectedRow()<<endl;
    // cout<<game_state.get_selectedColumn()<<endl;

    playMove(game_state);
    cout << "Selected row " << row << " and column " << col << endl;

    cout << "Game state after playMove:" << endl;

    cout << "Board:" << endl;

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (game_state.get_gameBoard(i, j) == 0) {
          cout << 'B' << " ";
        } else if (game_state.get_gameBoard(i, j) == 1) {
          cout << 'X' << ' ';
        } else {
          cout << '0' << ' ';
        }
      }
      cout << endl;
    }
    int move = game_state.get_moveValid();
    int over = game_state.get_gameOver();
    int code = game_state.get_winCode();

    if (move == 1) {
      cout << "moveValid: true" << endl;
    } else {
      cout << "moveValid: false" << endl;
    }

    if (over == 1) {
      cout << "gameOver: true" << endl;
    } else {
      cout << "gameOver: false" << endl;
    }
    cout << "winCode: " << code << endl;

    // The coordinates are valid; set the selectedRow and selectedColumn
    // members of the game state to the read values
    // Again, the corresponding mutators of GameState must be first
    // implemented before this works

    // ECE244 Student: add your code here

    // Call playMove

    // ECE244 Student: add your code here

    // Print the GameState object, as prescribed in the handout

    // ECE244 Student: add your code here
  }

  return 0;
}
