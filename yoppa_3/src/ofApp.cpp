#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	/* noise & sin
	ofBackground(0);
	ofPlanePrimitive plane; // �𐶐�
	plane.set(1000, 1000, 100, 100);
	mesh = plane.getMesh();
	*/

	ofBackground(0);
	ofEnableDepthTest();
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	cam.setDistance(400);
	myVideo.initGrabber(640, 480);
	mesh.setMode(OF_PRIMITIVE_POINTS);
}

//--------------------------------------------------------------
void ofApp::update() {
	/* sin�g��mesh
	float freq = 0.02; // �g�̎��g��
	float scale = 500; // �g�̍���

	// ���_�̐��������[�v
	for (int i = 0; i < mesh.getVertices().size(); i++) {
		// ���_��Z���W��sin��cos�ŕύX
		float x = mesh.getVertices()[i].x;
		float y = mesh.getVertices()[i].y;
		float zx = sin(ofGetElapsedTimef() + x * freq) * scale;
		float zy = tan(ofGetElapsedTimef() + y * freq) * scale;
		float z = zx + zy;
		mesh.setVertex(i, ofVec3f(x, y, z));
	}
	*/

	/* noise��mesh
	float div = 200.0; // noise�ׂ̍���
	float scale = 2000.0; // noise�̑傫��
	float speed = 1.5; // noise�̑��x
	for (int i = 0; i < mesh.getVertices().size(); i++) {
		float x = mesh.getVertices()[i].x;
		float y = mesh.getVertices()[i].y;
		float z = ofNoise(x / div, y / div, ofGetElapsedTimef()*speed) * scale;
		mesh.setVertex(i, ofVec3f(x, y, z));
	}
	*/

	myVideo.update(); // �J��������̉f�����X�V
	if (myVideo.isFrameNew()) { // �����J�����̃t���[�����X�V���ꂽ��
		mesh.clear(); // ���b�V����������
		ofPixels pixels = myVideo.getPixels(); // �J�����̉f����Pixel���𒊏o
		// Pixel���Ƃɏ���
		for (int i = 0; i < meshWidth; i++) {
			for (int j = 0; j < meshHeight; j++) {
				// Pixel��RGB�l���擾
				float r = (float)pixels[j * int(myVideo.getWidth()) * 3 + i * 3] / 255.0;
				float g = (float)pixels[j * int(myVideo.getWidth()) * 3 + i * 3 + 1] / 255.0;
				float b = (float)pixels[j * int(myVideo.getWidth()) * 3 + i * 3 + 2] / 255.0;
				// RGB���疾�x�𒊏o
				float brightness = (r + g + b) / 3.0f;

				// ���x���璸�_�̈ʒu��ݒ�
				ofVec3f vert = ofVec3f(i - meshWidth / 2, j - meshHeight / 2, brightness * 255.0);
				mesh.addVertex(vert);

				// ���_�̐F�̓J������Pixel�̒l�����̂܂܎g�p
				ofFloatColor color = ofFloatColor(r, g, b, 0.8);
				mesh.addColor(color);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	/* noise & sin
	cam.begin();
	ofPushMatrix();
	ofRotateY(180);
	mesh.setMode(OF_PRIMITIVE_POINTS);
	glPointSize(3.0);
	mesh.draw();
	ofPopMatrix();
	cam.end();
	*/

	// VBO�̕`��
	cam.begin();
	ofScale(1, -1, 1);
	glPointSize(3);
	mesh.draw();
	cam.end();

	// ���O�̕\��
	string info;
	info = "Vertex num = " + ofToString(numParticles, 0) + "\n";
	info += "FPS = " + ofToString(ofGetFrameRate(), 2);
	ofDrawBitmapString(info, 30, 30);
}

void ofApp::keyPressed(int key) {
	if (key == 'f') {
		ofToggleFullscreen();
	}
}
