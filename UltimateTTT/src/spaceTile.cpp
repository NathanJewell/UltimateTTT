#include "spaceTile.h"

#include "ofMain.h"
#include "Globals.h"
#include <iostream>

spaceTile::spaceTile(ofVec2f loc, ofVec2f s)
{
    location = loc;
    lw = s;
    clicked = false;
    state = 3;
    opacity = 0;
    //color = ofColor(100, 100, 100);
}

bool spaceTile::update(bool &player, bool hover)
{

    if(clicked == false)
    {
        if(player == false)//player one is blue
        {
            red = 0;
            blue = 255;
            green = 0;
        }
        else if(player == true)//player two is red
        {
            red = 255;
            green = 0;
            blue = 0;
        }
        if(hover == true)
        {
            if(mousePos.y < location.y-5 ||
            mousePos.y > location.y+lw.y+5 ||
            mousePos.x < location.x-5 ||
            mousePos.x > location.x+lw.x+5)
            {
                if(opacity > 10)
                {
                    opacity -= 10;

                }
                else{opacity= 0;}
                //opacity = 0;
            }
           else
           {
    //            std::cout << "here" << std::endl;
                if(opacity <= 251)
                {
                    opacity += 5;
                }
                if(mouseClicked == true)
                {
                    opacity = 255;
                    clicked = true;
                    state = player;
                    //player = !player;
                    return 1;
                }
                //opacity = 10;
            }
        }

        if(hover == false)
        {
            opacity = 0;
        }

    }

    color = ofColor(red, green, blue, opacity);
    return 0;
}

void spaceTile::draw()
{
    ofSetColor(color);
    ofRect(location.x, location.y, lw.x, lw.y);
}
