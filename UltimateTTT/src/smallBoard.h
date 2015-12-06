#pragma once

#include "ofMain.h"
#include "Globals.h"
#include "spaceTile.h"
class smallBoard
{
public:
    smallBoard(int);

    vector<spaceTile> tiles;
    vector< vector<int> > linePos;
    ofVec2f location;
    void makeMove(bool, int);
    int tileNum;
    bool won;
    int bgState;//0 = p1 won 1 = p2 won 2=nothing 3=active
    int bgr;
    int bgg;
    int bgb;
    int bgo;
    ofColor bgColor;


    void update(bool &player, int &currentBoard);
    void draw();







};
