#pragma once

#include "ofMain.h"

class spaceTile
{
public:
    spaceTile(ofVec2f, ofVec2f);

    ofVec2f location;
    ofColor color;
    ofVec2f lw;//length and width
    int state;//true = p1 false = p2 none = 2
    bool clicked;
    int opacity;
    int red;
    int green;
    int blue;


    bool update(bool&, bool);
    void draw();
};
