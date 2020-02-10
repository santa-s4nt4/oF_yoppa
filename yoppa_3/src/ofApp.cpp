#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	/* noise & sin
	ofBackground(0);
	ofPlanePrimitive plane; // 板を生成
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
	/* sin波のmesh
	float freq = 0.02; // 波の周波数
	float scale = 500; // 波の高さ

	// 頂点の数だけループ
	for (int i = 0; i < mesh.getVertices().size(); i++) {
		// 頂点のZ座標をsinとcosで変更
		float x = mesh.getVertices()[i].x;
		float y = mesh.getVertices()[i].y;
		float zx = sin(ofGetElapsedTimef() + x * freq) * scale;
		float zy = tan(ofGetElapsedTimef() + y * freq) * scale;
		float z = zx + zy;
		mesh.setVertex(i, ofVec3f(x, y, z));
	}
	*/

	/* noiseのmesh
	float div = 200.0; // noiseの細かさ
	float scale = 2000.0; // noiseの大きさ
	float speed = 1.5; // noiseの速度
	for (int i = 0; i < mesh.getVertices().size(); i++) {
		float x = mesh.getVertices()[i].x;
		float y = mesh.getVertices()[i].y;
		float z = ofNoise(x / div, y / div, ofGetElapsedTimef()*speed) * scale;
		mesh.setVertex(i, ofVec3f(x, y, z));
	}
	*/

	myVideo.update(); // カメラからの映像を更新
	if (myVideo.isFrameNew()) { // もしカメラのフレームが更新されたら
		mesh.clear(); // メッシュを初期化
		ofPixels pixels = myVideo.getPixels(); // カメラの映像のPixel情報を抽出
		// Pixelごとに処理
		for (int i = 0; i < meshWidth; i++) {
			for (int j = 0; j < meshHeight; j++) {
				// PixelのRGB値を取得
				float r = (float)pixels[j * int(myVideo.getWidth()) * 3 + i * 3] / 255.0;
				float g = (float)pixels[j * int(myVideo.getWidth()) * 3 + i * 3 + 1] / 255.0;
				float b = (float)pixels[j * int(myVideo.getWidth()) * 3 + i * 3 + 2] / 255.0;
				// RGBから明度を抽出
				float brightness = (r + g + b) / 3.0f;

				// 明度から頂点の位置を設定
				ofVec3f vert = ofVec3f(i - meshWidth / 2, j - meshHeight / 2, brightness * 255.0);
				mesh.addVertex(vert);

				// 頂点の色はカメラのPixelの値をそのまま使用
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

	// VBOの描画
	cam.begin();
	ofScale(1, -1, 1);
	glPointSize(3);
	mesh.draw();
	cam.end();

	// ログの表示
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
