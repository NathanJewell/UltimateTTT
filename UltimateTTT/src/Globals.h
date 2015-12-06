#pragma once
#include "ofMain.h"
#include "spaceTile.h"
#include <vector>
extern int boardSize;
extern int boardSizeSquared;
extern int boardWidth;
extern int boardHeight;
extern int margin;
extern int lineWidth;
extern int smallMargin;
extern int xValue [ 6 ];
extern ofVec2f mousePos;
extern bool mouseClicked;

bool isTTT(bool[]);
