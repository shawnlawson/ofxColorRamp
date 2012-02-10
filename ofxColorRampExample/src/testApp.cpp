#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	 
	counter = 0;
    bDrawDebug = false;
    myRamp = ofxColorRamp(256, 4, "imageRamp.png", 0.0);
    
    ofSetFrameRate(30);
    ofEnableBlendMode( OF_BLENDMODE_ALPHA );
}

//--------------------------------------------------------------
void testApp::update(){
	counter = counter + 0.01f;
    if( counter > 1.0 )
        counter = 0.0;
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0,0,0);
    
    ofSetColor( myRamp.getColor(counter) );
    ofCircle(100, 100, 100);
    
    if (bDrawDebug) 
        myRamp.debugDraw( 10, 110 );
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
    
    switch (key) {
        case 'd':
            bDrawDebug = !bDrawDebug;
            break;
            
        default:
            break;
    }
}
