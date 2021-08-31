#include "ofApp.h"
//#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("oscSoliClient");
	ofSetFrameRate(30);

	//Setup Sender Objects
	serverDestination = "localhost";
	serverPort = 10000;
	sender.setup(serverDestination, serverPort);

	//Gui Setup
	gui.setup("Data Collection for multi Soli experiment");
	gui.setSize(ofGetWidth() / 2.5, 10);


	//Client Selection Buttons
	gui.add(button1.setup("Client1"));
	gui.add(button2.setup("Client2"));
	gui.add(button3.setup("Client3"));
	gui.add(client.setup("Client", ""));
	//Participant Id entry
	gui.add(pidLabel.setup("ParticipantId", ""));
	//Repetitions for each gesture
	currentRepetition = 0;
	repetitions = 0;
	gui.add(repetitionLabel.setup("Repetitions:", (ofToString(currentRepetition) + "/" + ofToString(repetitions))));
	//Display Current Gesture set and gesture
	gui.add(gestureSetLabel.setup("Gesture Set", ""));
	gui.add(gestureLabel.setup("Gesture", ""));

}

//--------------------------------------------------------------
void ofApp::update(){
	if (button1) {
		//Setup Receiver
		receiver.setup(10001);
		clientID = 1;
		client = "1";
	}
	else if (button2) {
		//Setup Receiver
		receiver.setup(10002);
		clientID = 2;
		client = "2";
	}
	else if (button3) {
		//Setup Receiver
		receiver.setup(10003);
		clientID = 3;
		client = "3";
	}
	
	while (receiver.hasWaitingMessages()) {
		ofxOscMessage msg;
		receiver.getNextMessage(msg);
		if (msg.getAddress() == "/testInfo/repetitions") {
			repetitions = std::stoi(msg.getArgAsString(0));
			repetitionLabel = (ofToString(currentRepetition) + "/" + ofToString(repetitions));
		}
		else if (msg.getAddress() == "/testInfo/participantID") {
			pid = msg.getArgAsString(0);
			pidLabel = pid;
		}
		else if (msg.getAddress() == "/start") {
			start = msg.getArgAsString(0);
		}
		else if (msg.getAddress() == "/status") {
			if (msg.getArgAsInt(0) == clientID){
				ofxOscMessage status;
				status.setAddress("/status");
				status.addIntArg(clientID);
				sender.sendMessage(status);
			}
			
		}
	}

	
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}