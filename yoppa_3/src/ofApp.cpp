#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofEnableDepthTest();
	cam.setDistance(100);

	/* ofLight�܂�
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
	*/

	// ���b�V���̕��ƍ���
	w = 200;
	h = 200;

	// ���_�̐F��������
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			mesh.addColor(ofFloatColor(0.5, 0.8, 1.0));
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	// ���ׂĂ̒��_�����폜
	mesh.clearVertices();

	// ���ׂĂ̒��_�̈ʒu���X�V���Ē��_���Ƃ��Ēǉ�
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
	/* ofLight�܂�
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

	ofSetHexColor(0xffffff); // ���b�V���̕`��
	cam.begin();

	// ���_�̈ʒu���h�b�g�ŕ\��
	glPointSize(2.0);
	glEnable(GL_POINT_SMOOTH);
	mesh.drawVertices();

	cam.end();

	string info;
	info = "Vertex num = " + ofToString(w * h, 0) = "\n";
	info += "FPS = " + ofToString(ofGetFrameRate(), 2);
	ofDrawBitmapString(info, 30, 30);
}