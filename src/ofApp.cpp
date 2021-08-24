#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("oscSoliClient");
	ofSetFrameRate(30);


	//Gui Setup
	gui.setup("Data Collection for multi Soli experiment");
	gui.setSize(ofGetWidth() / 2.5, 10);

	//Participant Id entry
	gui.add(pidLabel.setup("ParticipantId:", ""));
	//Repetitions for each gesture
	gui.add(repetitionLabel.setup("Repetitions:", "0/0"));
	//Display Current Gesture set and gesture
	gui.add(gestureSetLabel.setup("Gesture Set:", ""));
	gui.add(gestureLabel.setup("Gesture:", ""));
}

//--------------------------------------------------------------
void ofApp::update(){

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