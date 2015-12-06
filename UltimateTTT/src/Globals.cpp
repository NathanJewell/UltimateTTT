#include "Globals.h"

int boardSize = 3;
int boardSizeSquared = boardSize*boardSize;
int boardWidth = 0;
int boardHeight = 0;
int margin = 50;
int lineWidth = 4;
int smallMargin = 15;
int xValue[6];
ofVec2f mousePos;
bool mouseClicked;
//boardHeight/boardSize - 2*smallMargin;
//these are the 6 x and y values for the lines on the small 3x3s.
//xValue [ 0 ] = ( ( ( boardWidth / boardSize ) - ( 2 * smallMargin ) ) / boardSize ) + margin + smallMargin - ( lineWidth / 2 / 2 );
//xValue [ 1 ] = 2 * ( ( ( boardWidth / boardSize ) - ( 2 * smallMargin ) ) / boardSize ) + margin + smallMargin - ( lineWidth / 2 / 2 );
//xValue [ 2 ] = 4 * ( ( ( boardWidth / boardSize ) - ( 2 * smallMargin ) ) / boardSize ) + margin + ( 3 * smallMargin ) - ( lineWidth / 2 / 2 );
//xValue [ 3 ] = 5 * ( ( ( boardWidth / boardSize ) - ( 2 * smallMargin ) ) / boardSize ) + margin + ( 3 * smallMargin ) - ( lineWidth / 2 / 2 );
//xValue [ 4 ] = 7 * ( ( ( boardWidth / boardSize ) - ( 2 * smallMargin ) ) / boardSize ) + margin + ( 5 * smallMargin ) - ( lineWidth / 2 / 2 );
//xValue [ 5 ] = 8 * ( ( ( boardWidth / boardSize ) - ( 2 * smallMargin ) ) / boardSize ) + margin + ( 5 * smallMargin ) - ( lineWidth / 2 / 2 );

bool isTTT ( bool player1[])
{
    if ( player1[0] == true and player1[1] == true and player1[2] == true ) {
        return 1;
    }
    else if ( player1[3] == true and player1[4] == true and player1[5] == true ) {
        return 1;
    }
    else if ( player1[6] == true and player1[7] == true and player1[8] == true ) {
        return 1;
    }
    else if ( player1[0] == true and player1[3] == true and player1[6] == true ) {
        return 1;
    }
    else if ( player1[1] == true and player1[4] == true and player1[7] == true ) {
        return 1;
    }
    else if ( player1[2] == true and player1[5] == true and player1[8] == true ) {
        return 1;
    }
    else if ( player1[0] == true and player1[4] == true and player1[8] == true ) {
        return 1;
    }
    else if ( player1[2] == true and player1[4] == true and player1[6] == true ) {
        return 1;
    }
    else
    {
        return 0;
    }

}
