#include "ofApp.h"
#include "bigBoard.h"
#include "string.h"
//--------------------------------------------------------------
void ofApp::setup(){
    gameState = 2;
    ofSetFrameRate(60);
    boardWidth = ofGetWindowWidth()-margin*2;
    boardHeight = ofGetWindowHeight()-margin*2;
    xValue [ 0 ] = ( ( ( boardWidth / boardSize ) - ( 2 * smallMargin ) ) / boardSize ) + margin + smallMargin - ( lineWidth / 2 / 2 );
    xValue [ 1 ] = 2 * ( ( ( boardWidth / boardSize ) - ( 2 * smallMargin ) ) / boardSize ) + margin + smallMargin - ( lineWidth / 2 / 2 );
    xValue [ 2 ] = 4 * ( ( ( boardWidth / boardSize ) - ( 2 * smallMargin ) ) / boardSize ) + margin + ( 3 * smallMargin ) - ( lineWidth / 2 / 2 );
    xValue [ 3 ] = 5 * ( ( ( boardWidth / boardSize ) - ( 2 * smallMargin ) ) / boardSize ) + margin + ( 3 * smallMargin ) - ( lineWidth / 2 / 2 );
    xValue [ 4 ] = 7 * ( ( ( boardWidth / boardSize ) - ( 2 * smallMargin ) ) / boardSize ) + margin + ( 5 * smallMargin ) - ( lineWidth / 2 / 2 );
    xValue [ 5 ] = 8 * ( ( ( boardWidth / boardSize ) - ( 2 * smallMargin ) ) / boardSize ) + margin + ( 5 * smallMargin ) - ( lineWidth / 2 / 2 );
    bigBoard tmp;
    tmp.currentPlayer = false;
    gameBoard.push_back(tmp);
}

//--------------------------------------------------------------
void ofApp::update(){
    if(gameState == 2)
    {
        gameBoard[0].update(gameState);
    }
    else if(gameState == 0)
    {

    }
    else if(gameState == 1)
    {

    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(gameState == 2)
    {
        gameBoard[0].draw();
    }
    else if(gameState == 0)
    {
        ofSetColor(0, 0, 255);
        ofRect(0, 0, 1000, 1000);
    }
    else if(gameState == 1)
    {
        ofSetColor(255, 0, 0);
        ofRect(0, 0, 1000, 1000);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mousePos.x = x;
    mousePos.y = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mouseClicked = 1;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    mouseClicked = 0;
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
