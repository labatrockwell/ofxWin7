// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

// ofWinGestureEngine.h
//
// Definition of derived class that handles gesture operations. This
// class get pointer to the rectangle object through constructor and
// then it just invokes coresponding function from CDrawingObject class

#pragma once
#include "gestureengine.h"
#include "ofBaseTouchApp.h"

class ofWinGestureEngine :
    public CGestureEngine
{
public:
    ofWinGestureEngine(ofBaseTouchApp* ofAppPtr);
public:
    ~ofWinGestureEngine(void);

    // Functions that are handling gesture commands
    virtual void ProcessRollover(void);
    virtual void ProcessTwoFingerTap(void);
    virtual void ProcessMove(const LONG ldx, const LONG ldy);
    virtual void ProcessZoom(const double dZoomFactor,const LONG lZx,const LONG lZy);
    virtual void ProcessRotate(const double dAngle,const LONG lOx,const LONG lOy);
	void setAppPointer(ofBaseTouchApp * ofAppPtr);

private:
    ofBaseTouchApp * _ofAppPtr;
};
