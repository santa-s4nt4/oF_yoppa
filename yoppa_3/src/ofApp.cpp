#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofEnableDepthTest();
	ofEnableSmoothing();

	light.enable();
	// 照明の位置
	light.setPosition(-300, 300, 500);
	// 環境反射光の色
	light.setAmbientColor(ofFloatColor(0.5, 0.2, 0.2, 1.0));
	// 拡散反射光の色
	light.setDiffuseColor(ofFloatColor(0.5, 0.5, 1.0));
	// 鏡面反射光の色
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