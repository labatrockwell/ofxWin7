// You MUST add this before ofMain is included
// it tells Windows you're using Win7+
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0601
#endif


#include "testApp.h"
#include "ofWinGlutWindow.h"

//--------------------------------------------------------------
int main(){
	ofWinGlutWindow window; // create a window
	// set width, height, mode (OF_WINDOW or OF_FULLSCREEN)
	ofSetupOpenGL(&window, 1024, 768, OF_WINDOW);
	ofRunApp(new testApp()); // start the app
}
