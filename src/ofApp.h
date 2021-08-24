#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxGui.h"
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

		//GUI
		ofxPanel gui;

		ofxButton button;
		ofxLabel pidLabel;
		ofxLabel repetitionLabel;
		ofxLabel gestureSetLabel;
		ofxLabel gestureLabel;



};
