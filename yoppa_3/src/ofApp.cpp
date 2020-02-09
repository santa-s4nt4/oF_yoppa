#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);
	//板を生成
	ofPlanePrimitive plane;
	plane.set(1000, 1000, 100, 100);
	//生成した板からメッシュを抽出
	mesh = plane.getMesh();
}

//--------------------------------------------------------------
void ofApp::update() {
	float freq = 0.02; //波の周波数
	float scale = 50.0; //波の高さ
	//頂点の数だけループ
	for (int i = 0; i < mesh.getVertices().size(); i++) {
		//頂点のZ座標をsinとcosで変更
		float x = mesh.getVertices()[i].x;
		float y = mesh.getVertices()[i].y;
		float zx = sin(ofGetElapsedTimef() + x * freq) * scale;
		float zy = cos(ofGetElapsedTimef() + y * freq)  * scale;
		float z = zx + zy;
		mesh.setVertex(i, ofVec3f(x, y, z));
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	cam.begin();
	ofPushMatrix();
	ofRotateX(-45);
	//頂点をポイントで描画
	mesh.setMode(OF_PRIMITIVE_POINTS);
	glPointSize(3.0);
	mesh.draw();
	ofPopMatrix();
	cam.end();

	string info;
	info = "Vertex num = " + ofToString(w * h, 0) = "\n";
	info += "FPS = " + ofToString(ofGetFrameRate(), 2);
	ofDrawBitmapString(info, 30, 30);
}