#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofEnableDepthTest();
	cam.setDistance(100);

	/* ofLightまで
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
	*/

	// メッシュの幅と高さ
	w = 200;
	h = 200;

	// 頂点の色を初期化
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			mesh.addColor(ofFloatColor(0.5, 0.8, 1.0));
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	// すべての頂点情報を削除
	mesh.clearVertices();

	// すべての頂点の位置を更新して頂点情報として追加
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			float x = sin(i * 0.1 + ofGetElapsedTimef())*10.0;
			float y = sin(j * 0.15 + ofGetElapsedTimef())*10.0;
			float z = x + y;
			mesh.addVertex(ofVec3f(i - w / 2, j - h / 2, z));
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	/* ofLightまで
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
	*/

	ofSetHexColor(0xffffff); // メッシュの描画
	cam.begin();

	// 頂点の位置をドットで表示
	glPointSize(2.0);
	glEnable(GL_POINT_SMOOTH);
	mesh.drawVertices();

	cam.end();

	string info;
	info = "Vertex num = " + ofToString(w * h, 0) = "\n";
	info += "FPS = " + ofToString(ofGetFrameRate(), 2);
	ofDrawBitmapString(info, 30, 30);
}