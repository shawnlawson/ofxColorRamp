//
//  ofxColorRamp.h
//
//  Created by Shawn Lawson on 1/17/12.
//  Copyright (c) 2012 RPI. All rights reserved.
//




class ofxColorRamp{
    
public:
    ofImage rampImage;
    
    ofxColorRamp(){};
    
    ofxColorRamp(int width, int height, string imageToLoad){
        ofxColorRamp(width, height, imageToLoad, 0.0);
    }
    
    ofxColorRamp(int width, int height, string imageToLoad, float rSample){
        
        if (width >= height) //take larger in case image is vertical
            bSampleWidth = true;
        else
            bSampleWidth = false;
        
        randomSample = ofClamp(rSample, 0, 1.0);
        
        rampImage.allocate( width, height, OF_IMAGE_COLOR_ALPHA);
        rampImage.loadImage(imageToLoad);
    }
    
    ofColor getColor( float location ){
                    
        float randomAmount = ofRandom( -randomSample, randomSample );        
        
        if( bSampleWidth ){
            sampleLocation = floor( ofClamp(location+randomAmount, 0.0, 1.0)*rampImage.getWidth()-1 );
            return rampImage.getColor( sampleLocation, 0 );
        }else{
            sampleLocation = floor( ofClamp(location+randomAmount, 0.0, 1.0)*rampImage.getHeight()-1 );
            return rampImage.getColor( 0, sampleLocation );
        }
    }
    
    void debugDraw( int x = 0, int y = 0){
        
        ofSetColor(255);
        ofPushMatrix();
        ofTranslate(x, y);
        rampImage.draw(0, 0);


        if( bSampleWidth ){
            ofLine(sampleLocation, 0, sampleLocation, rampImage.getHeight());
            ofColor temp = rampImage.getColor(sampleLocation, 0);
            stringstream    ss;
            ss << "r: " << (int)temp.r << "\ng: " << (int)temp.g 
            << "\nb: " << (int)temp.b << "\na: " << (int)temp.a;

            ofDrawBitmapString(ss.str(), 0, rampImage.getHeight()+10);
        }else{
            ofLine(0, sampleLocation, rampImage.getWidth(), sampleLocation);    
            ofColor temp = rampImage.getColor(sampleLocation, 0);
            stringstream    ss;
            ss << "r: " << (int)temp.r << "\ng: " << (int)temp.g 
            << "\nb: " << (int)temp.b << "\na: " << (int)temp.a;
            
            ofDrawBitmapString(ss.str(), 0, rampImage.getHeight()+10);        
        }
        ofPopMatrix();
        
    }
                                  
private:

    float   randomSample; 
    bool    bSampleWidth; 
    int     sampleLocation;
                                  
};