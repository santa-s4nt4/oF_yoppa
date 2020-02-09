#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();

	//ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofSetColor(255);

	box.set(200);
	box.setPosition(-150, 0, 0);
	box.drawWireframe();

	sphere.set(100, 16);
	sphere.setPosition(150, 0, 0);
	sphere.drawWireframe();

	cam.end();
}