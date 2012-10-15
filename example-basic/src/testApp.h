#pragma once

#include "ofMain.h"
#include "ofBaseTouchApp.h"

class testApp : public ofBaseTouchApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// win7 events
		void touchDown(int id, int x, int y);
		void touchMove(int id, int x, int y);
		void touchUp(int id, int x, int y);

		// NOTE: you must call setUseGestures() in your main.cpp to use these last two
		void twoFingerTap();
		void twoFingerZoom(double dZoomFactor,const LONG lZx,const LONG lZy);

		
		// quick map to store current touches
		map<int,ofPoint> touches;
};
