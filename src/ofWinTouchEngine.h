#pragma once

#include "ofBaseTouchApp.h"

class ofWinTouchEngine{
    
public:
    ofWinTouchEngine(ofBaseTouchApp* ofAppPtr);
    ~ofWinTouchEngine(void);
    
	virtual void OnTouchDown(int id, int x, int y);
	virtual void OnTouchMove(int id, int x, int y);
	virtual void OnTouchUp(int id, int x, int y);
    
	LRESULT processTouch(HWND hWnd, WPARAM wParam, LPARAM lParam);
    
	void setAppPointer(ofBaseTouchApp * ofAppPtr);
	
private:
   ofBaseTouchApp * _ofAppPtr;
};
