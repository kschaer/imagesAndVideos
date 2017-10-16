#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    imgIterator = 5;
    
    imgSize = 500;
    //myImage.load("type2.png");
    
    myImage.allocate(imgSize, imgSize, OF_IMAGE_COLOR);
    
    ofSetBackgroundColor(1);
    color.set(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < 500; i++){
        for (int j = 0; j <500; j++){
            float dist =ofDist(i, j, mouseX, mouseY);
            float mappedDist = ofMap(dist, 0, 707,0,255);
            color.set(mappedDist-i/2,mappedDist/2+j,255-mappedDist+j/2);
            myImage.setColor(i,j,color);
        }
    }
    myImage.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    for (int i = 0; i < myImage.getWidth(); i+=imgIterator){ //or i+=10 would get every ten pixels, for instance
        for (int j = 0; j < myImage.getHeight(); j+=imgIterator){
            
            ofColor c = myImage.getColor(i,j);
            float brightness = c.getBrightness();
            
            float dist =ofDist(i, j, mouseX, mouseY);
            float mappedDist = ofMap(dist, 0, 707,0,255);
            color.set(mappedDist-i/2,mappedDist/2+j,255-mappedDist+j/2);
            ofSetColor(color);
            
            
            //little lines in a grid, rotate based on brightness*a wave
            ofPushMatrix();
            ofTranslate(i,j);
            //ofRotateY(360*sin(ofGetElapsedTimef()*.1));
            ofRotateZ(ofMap(brightness, 0, 255, 0, 360*sin(.2*ofGetElapsedTimef())));
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
