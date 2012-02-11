/*
    ofxColorRamp.h
 
  Created by Shawn Lawson on 1/17/12.
  http://www.shawnlawson.com
  
  Copyright (c) 2012 Shawn Lawson
 
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/




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