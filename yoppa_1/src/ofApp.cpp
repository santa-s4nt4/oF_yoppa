#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofSetBackgroundColor(0);
	location = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);
	velocity = ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10));
}

//--------------------------------------------------------------
void ofApp::update(){
	location += velocity;
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(31, 12, 255);
	ofDrawCircle(location, 40);
	if (location.x < 0 || location.x > ofGetWidth()) {
		velocity.x *= -1;
	}
	if (location.y < 0 || location.y > ofGetWindowHeight()) {
		velocity.y *= -1;
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
