#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		int meshWidth = 640;
		int meshHeight = 480;
		int numParticles = meshWidth * meshHeight;

		//ofBoxPrimitive box;
		// ofSpherePrimitive sphere;
		ofEasyCam cam;
		ofVboMesh mesh;
		//ofLight light;
		ofVideoGrabber myVideo;
};
