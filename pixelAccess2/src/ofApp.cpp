#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    imgIterator = 30;
    
    imgSize = 1000;
    //myImage.load("type2.png");
    
    myImage.allocate(imgSize, imgSize, OF_IMAGE_COLOR);
    
    ofSetBackgroundColor(90,200,244);
    color.set(0);
    ofSetBackgroundAuto(false);
    ofHideCursor();
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < imgSize; i++){
        for (int j = 0; j <imgSize; j++){
            float dist =ofDist(i, j, mouseX, mouseY);
            float mappedDist = ofMap(dist, 0, 1414,0,255);
            color.set(mappedDist-i/2,mappedDist/2+j,255-mappedDist+j/2);
            myImage.setColor(i,j,color);
        }
    }
    myImage.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0,0,0,20);
    ofDrawRectangle(0,0,width*2,height*2);
    //cam.enableOrtho();
    cam.begin();
    ofPushMatrix();
    ofRotateX(180);

    ofTranslate(-width/2, -height/3);
    
    for (int i = 0; i < myImage.getWidth(); i+=imgIterator){ //or i+=10 would get every ten pixels, for instance
        for (int j = 0; j < myImage.getHeight(); j+=imgIterator){
            for (int k = 0; k < 20; k++){
                
            
            
            ofColor c = myImage.getColor(i,j);
            float brightness = c.getBrightness();
            
            float dist =ofDist(i, j, mouseX, mouseY);
            float mappedDist = ofMap(dist, 0, 707,0,255);
            color.set(mappedDist-i/2,mappedDist/2+j,255-mappedDist+j/2);
            ofSetColor(color);
            
            
            //little lines in a grid, rotate based on brightness*a wave
            ofPushMatrix();
            ofTranslate(width/2,height/2);
            ofRotateY(.5*brightness+k);
                ofRotateZ(j);
            ofTranslate(i,j);
            //ofRotateY(360*sin(ofGetElapsedTimef()*.1));
            //ofRotateZ(ofMap(brightness, 0, 255, 0, 360*sin(.2*ofGetElapsedTimef())));
            
            ofRotateZ(mouseX);
            ofDrawLine(0,0, brightness, 0,0,k);
            //ofDrawTriangle(-10, -10, 0, 5*brightness*.01, 10, -10);
            //ofDrawCircle(-5,-5, 20*k, 10);
                //ofDrawSphere(-5,5,10*k,3+k%10);
            ofPopMatrix();
            
            
            }
        }
    }
    ofPopMatrix();
    cam.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
