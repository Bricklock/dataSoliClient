#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void windowResized(int w, int h);
		
		//Sender
		ofxOscSender sender;
		string serverDestination;
		int serverPort;

		//Receiver
		ofxOscReceiver receiver;
		int receivePort;

};
