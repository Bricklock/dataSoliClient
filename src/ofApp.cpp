#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("oscSoliClient");
	ofSetFrameRate(30);


	//Setup Sender Objects
	serverDestination = "localhost";
	serverPort = 10000;
	sender.setup(serverDestination, serverPort);
	//sender.setup(clientDestination2, clientPort2);
	//sender.setup(clientDestination3, clientPort3);

	//Setup Receiver Objects
	receiver.setup(10001);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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