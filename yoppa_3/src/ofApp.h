#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		//ofBoxPrimitive box;
		// ofSpherePrimitive sphere;
		ofEasyCam cam;
		ofVboMesh mesh;
		//ofLight light;
};
