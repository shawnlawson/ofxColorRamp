#pragma once

#include "ofMain.h"
#include "ofxColorRamp.h"

class testApp : public ofBaseApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		
				
		float 			counter;
        bool            bDrawDebug;
        ofxColorRamp    myRamp;
};

