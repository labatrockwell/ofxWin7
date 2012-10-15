//
//  ofBaseTouchApp.h
//  Blooms
//
//  Created by rockwell on 10/12/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#pragma once
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0601
#endif

#include "ofMain.h"

class ofBaseTouchApp : public ofBaseApp
{
public:
    
    virtual void twoFingerTap(){}
    virtual void twoFingerZoom(double dZoomFactor,const LONG lZx,const LONG lZy) {}
    virtual void touchDown(int id, int x, int y){}
    virtual void touchMove(int id, int x, int y){}
    virtual void touchUp(int id, int x, int y){}
};

