#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofEnableDepthTest();
	ofEnableSmoothing();

	light.enable();
	// �Ɩ��̈ʒu
	light.setPosition(-300, 300, 500);
	// �����ˌ��̐F
	light.setAmbientColor(ofFloatColor(0.5, 0.2, 0.2, 1.0));
	// �g�U���ˌ��̐F
	light.setDiffuseColor(ofFloatColor(0.5, 0.5, 1.0));
	// ���ʔ��ˌ��̐F
	light.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0));
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
	//box.drawWireframe();
	box.draw();

	sphere.set(100, 16);
	sphere.setPosition(150, 0, 0);
	//sphere.drawWireframe();
	sphere.draw();

	cam.end();
}