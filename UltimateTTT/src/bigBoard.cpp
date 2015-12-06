#include "bigBoard.h"
#include "Globals.h"
#include "ofMain.h"
#include "smallBoard.h"

bigBoard::bigBoard()
{
    currentPlayer = 1;
    currentTile = 4;
    for(int ii = 0; ii < boardSizeSquared; ii++)
    {
        smallBoard tmp(ii);
        tmp.location == ofVec2f(((ii+1%boardSize)*(boardWidth/boardSize)));
        //tmp.tileNum = ii;
        smallTiles.push_back(tmp);
    }
}



void bigBoard::makeMove(int tile)
{
    //smallTiles[currentTile].makeMove(currentPlayer, tile);
}

void bigBoard::update(int& gameState)
{
    if(currentTile > 0)
    {
        if(smallTiles[currentTile].won == true)
        {
            currentTile = -1;
            std::cout << currentTile << std::endl;
        }
    }

    for(int ii = 0; ii < smallTiles.size(); ii++)
    {
        if(smallTiles[ii].won != true)
        {
            if(ii == currentTile || currentTile < 0)
            {
                smallTiles[ii].bgState = 3;
            }
            else{smallTiles[ii].bgState = 2;}
            smallTiles[ii].update(currentPlayer, currentTile);
        }


    }
    bool logicA[9];
    bool aPlayer = !currentPlayer;
    for(int ii = 0; ii < smallTiles.size(); ii++)
    {

        if(smallTiles[ii].bgState == aPlayer)
        {
            logicA[ii] = true;
        }
        else{logicA[ii] = false;}

    }
    if(isTTT(logicA))
    {
        gameState = aPlayer;
    }
}

void bigBoard::draw()
{
    ofSetColor(ofColor(0, 0, 0));
    ofRect ( (  boardWidth / boardSize ) - ( lineWidth / 2 ) + margin , margin, lineWidth, boardWidth );
    ofRect ( 2 * ( boardWidth / boardSize ) - ( lineWidth / 2 ) + margin, margin, lineWidth, boardWidth );
    ofRect ( margin, ( boardHeight / boardSize ) - ( lineWidth / 2 ) + margin, boardWidth, lineWidth );
    ofRect ( margin, 2 * ( boardHeight / boardSize ) - ( lineWidth / 2 ) + margin, boardWidth, lineWidth );
    for ( int ii = 0; ii < smallTiles.size(); ii ++ ) {
        smallTiles [ ii ].draw();
    }
}
