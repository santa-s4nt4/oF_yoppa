#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);
	//�𐶐�
	ofPlanePrimitive plane;
	plane.set(1000, 1000, 100, 100);
	//�����������烁�b�V���𒊏o
	mesh = plane.getMesh();
}

//--------------------------------------------------------------
void ofApp::update() {
	float freq = 0.02; //�g�̎��g��
	float scale = 50.0; //�g�̍���
	//���_�̐��������[�v
	for (int i = 0; i < mesh.getVertices().size(); i++) {
		//���_��Z���W��sin��cos�ŕύX
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
	//���_���|�C���g�ŕ`��
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