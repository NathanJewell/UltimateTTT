#pragma once

#include "ofMain.h"
#include "smallBoard.h"

class bigBoard {

    public:
        bigBoard();
        int currentTile;//tells the tile that the next player must move on
        bool currentPlayer;//true = player1, false = player2
        std::vector<smallBoard> smallTiles;

        void update(int&);
        void draw();//draws the large tictactoe board to the screen
        void makeMove(int);//


};
