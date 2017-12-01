#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	float size = 300;
	float box_size = 30;

	this->cam.begin();
	ofRotateY(ofGetFrameNum());

	for (float x = -size; x <= size; x += box_size) {
		for (float z = -size; z <= size; z += box_size) {
			for (float y = 0; y <= (size * 2) * ofMap(ofNoise(x * 0.0025, z * 0.0025 + ofGetFrameNum() * 0.05), 0, 1, 0, 0.9); y += box_size) {
				ofPushMatrix();
				ofTranslate(ofVec3f(x, y, z));

				ofColor box_color;
				box_color.setHsb(255 - y / (size * 2) * 255, 255, 255);
				ofSetColor(box_color);

				this->box.set(box_size);
				this->box.draw();

				ofPopMatrix();
			}
		}
	}
	
	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}