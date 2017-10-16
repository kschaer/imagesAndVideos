#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    imgIterator = 3;
    
    myImage.load("type2.png");
    
    ofSetBackgroundColor(1);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    

    
    for (int i = 0; i < myImage.getWidth(); i+=imgIterator){ //or i+=10 would get every ten pixels, for instance
        for (int j = 0; j < myImage.getHeight(); j+=imgIterator){
            
            ofColor c = myImage.getColor(i,j);
            float brightness = c.getBrightness();
            ofSetColor(c.getBrightness());

            
            //little lines in a grid, rotate based on brightness*a wave            ofPushMatrix();
            ofTranslate(i,j);
            ofRotateZ(ofMap(brightness, 0, 255, 0, 360*sin(ofGetElapsedTimef())));
            ofDrawLine(-.05*(100+255-brightness),0,.08*(255-brightness),0);
            ofPopMatrix();
            
            
            
        }
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
