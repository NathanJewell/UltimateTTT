#include "smallBoard.h"
#include "Globals.h"
#include "spaceTile.h"
#include <iostream>
smallBoard::smallBoard(int tnum)
{
    won = false;
    bgState = 2;
    bgo = 0;
    bgr =0;
    bgg = 0;
    bgb = 0;
    ofVec2f xy[9];
    tileNum = tnum;
    linePos.resize(4);
    for(int ii = 0; ii < 4; ii++)
    {
        linePos[ii].resize(4);
    }
    if(tileNum < 3)//0-2
    {
        linePos[0][0] = xValue[2*tileNum], linePos[1][0] = 65+(270*(tileNum / 3)), linePos[2][0] = lineWidth / 2, linePos[3][0] = boardWidth / boardSize - ( 2 * smallMargin );
        linePos[0][1] = xValue[1+(tileNum*2)], linePos[1][1] = 65+(270*(tileNum / 3)), linePos[2][1] = lineWidth / 2, linePos[3][1] = boardWidth / boardSize - ( 2 * smallMargin ) ;
        linePos[0][2] = margin+((1+(2*tileNum))*smallMargin)+(270*(tileNum)), linePos[1][2] = xValue[0], linePos[2][2] = boardWidth / boardSize - ( 2 * smallMargin ),linePos[3][2] = lineWidth / 2;
        linePos[0][3] = margin+((1+(2*tileNum))*smallMargin)+(270*(tileNum)),linePos[1][3] = xValue[1], linePos[2][3] = boardWidth / boardSize - ( 2 * smallMargin ), linePos[3][3] =lineWidth / 2;
    }
    else if(tileNum < 6)//3-5
    {
        linePos[0][0] = xValue[2*(tileNum-3)],linePos[1][0] = 95+(270*(tileNum / 3)),linePos[2][0] = lineWidth / 2,linePos[3][0] = boardWidth / boardSize - ( 2 * smallMargin ) ;
        linePos[0][1] = xValue[1+(2*(tileNum-3))], linePos[1][1] = 95+(270*(tileNum / 3)), linePos[2][1] = lineWidth / 2, linePos[3][1] = boardWidth / boardSize - ( 2 * smallMargin ) ;
        linePos[0][2] = margin+((1+(2*(tileNum-3)))*smallMargin)+(270*(tileNum-3)), linePos[1][2] = xValue[2], linePos[2][2] = boardWidth / boardSize - ( 2 * smallMargin ), linePos[3][2] = lineWidth / 2;
        linePos[0][3] = margin+((1+(2*(tileNum-3)))*smallMargin)+(270*(tileNum-3)), linePos[1][3] = xValue[3], linePos[2][3] = boardWidth / boardSize - ( 2 * smallMargin ), linePos[3][3] = lineWidth / 2;
    }
    else if(tileNum < 10)//6-8
    {
        linePos[0][0] = xValue[2*(tileNum-6)], linePos[1][0] = 125+(270*(tileNum / 3)), linePos[2][0] = lineWidth / 2, linePos[3][0] = boardWidth / boardSize - ( 2 * smallMargin );
        linePos[0][1] = xValue[1+(2*(tileNum-6))], linePos[1][1] = 125+(270*(tileNum / 3)), linePos[2][1] = lineWidth / 2, linePos[3][1] = boardWidth / boardSize - ( 2 * smallMargin );
        linePos[0][2] = margin+((1+(2*(tileNum-6)))*smallMargin)+(270*(tileNum-6)), linePos[1][2] = xValue[4], linePos[2][2] = boardWidth / boardSize - ( 2 * smallMargin ), linePos[3][2] = lineWidth / 2;
        linePos[0][3] = margin+((1+(2*(tileNum-6)))*smallMargin)+(270*(tileNum-6)), linePos[1][3] = xValue[5], linePos[2][3] = boardWidth / boardSize - ( 2 * smallMargin ), linePos[3][3] = lineWidth / 2;
    }

    xy[0].x = linePos[0][0]-84, xy[0].y = linePos[1][2]-84;
    xy[1].x = linePos[0][0]+6, xy[1].y = linePos[1][2]-84;
    xy[2].x = linePos[0][0]+96, xy[2].y = linePos[1][2]-84;
    xy[3].x = linePos[0][0]-84, xy[3].y = linePos[1][2]+6;
    xy[4].x = linePos[0][0]+6, xy[4].y = linePos[1][2]+6;
    xy[5].x = linePos[0][0]+96, xy[5].y = linePos[1][2]+6;
    xy[6].x = linePos[0][0]-84, xy[6].y = linePos[1][2]+96;
    xy[7].x = linePos[0][0]+6, xy[7].y = linePos[1][2]+96;
    xy[8].x = linePos[0][0]+96, xy[8].y = linePos[1][2]+96;


    std::cout << tileNum << std::endl;
    for ( int ii = 0; ii < 9; ii ++) {
        std::cout << "x: " << xy[ii].x << std::endl;
        std::cout << "y: " << xy[ii].y << std::endl;
    }
    //tiles.resize(9);
    for(int ii = 0; ii < 9; ii++)
    {
        spaceTile tmp(xy[ii], ofVec2f(80, 80));
        tmp.state = 3;
        tiles.push_back(tmp);
    }
}

void smallBoard::makeMove(bool player, int tilenum)
{


}

void smallBoard::update(bool &player, int &currentBoard)
{
    //std::cout << mousePos << std::endl;
    for(int ii = 0; ii < tiles.size(); ii++)
    {
        //std::cout << currentBoard << ", " << tileNum << std::endl;
        if(currentBoard == tileNum || currentBoard < 0)
        {
            if(tiles[ii].update(player, 1))
            {
                bool clickedTiles[9];
                for(int ii = 0; ii < 9; ii++)
                {
                    if(tiles[ii].state == player)
                    {
                        clickedTiles[ii] = true;
                    }
                    else{clickedTiles[ii] = false;}
                    std::cout << ii << ": " << clickedTiles[ii] << std::endl;
                }
                std::cout << std::endl;
                if(isTTT(clickedTiles))
                {
                    bgState = player;
                    won = true;
                }
                currentBoard = ii;
                player = !player;
            }
        }
        else{tiles[ii].update(player, 0);}

    }

    if(bgState == 0)
    {
        bgr = 0; bgg = 0; bgb = 255; bgo = 100;// set color to blue(player 1)
    }
    else if(bgState == 1)
    {
        bgr = 255; bgg = 0; bgb = 0; bgo = 100;// set color to red (player 2)
    }
    else if(bgState == 2)
    {
        bgr = 0; bgg = 0; bgb = 0; bgo = 0;
    }
    else if(bgState = 3)
    {
        bgr = 255; bgg = 230; bgb = 140; bgo = 100; // set color to khaki
    }
    bgColor = ofColor(bgr, bgg, bgb, bgo);

}
void smallBoard::draw()
{
    ofSetColor(bgColor);
    ofRect(linePos[0][0]-89, linePos[1][2]-89, 270, 270);
    ofSetColor(ofColor(0, 0, 0));
    ofRect(linePos[0][0], linePos[1][0], linePos[2][0], linePos[3][0]);
    ofRect(linePos[0][1], linePos[1][1], linePos[2][1], linePos[3][1]);
    ofRect(linePos[0][2], linePos[1][2], linePos[2][2], linePos[3][2]);
    ofRect(linePos[0][3], linePos[1][3], linePos[2][3], linePos[3][3]);
    for(int ii = 0; ii < tiles.size(); ii++)
    {
        tiles[ii].draw();
    }

}



