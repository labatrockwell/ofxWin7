// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//
// MyGestureEngine.cpp: implementation of ofWinGestureEngine class

#include "ofWinGestureEngine.h"

// Constructor
// in:
//      pcRect - pointer to the CDrawingObject class (rectangle)
ofWinGestureEngine::ofWinGestureEngine(ofBaseTouchApp * ofAppPtr):
    CGestureEngine(),
    _ofAppPtr(ofAppPtr)
{
}

// Destructor
ofWinGestureEngine::~ofWinGestureEngine(void)
{
}

// Rollover command
void ofWinGestureEngine::ProcessRollover(void)
{
    if(_ofAppPtr)
    {
    }
}

// Two finger tap command
void ofWinGestureEngine::ProcessTwoFingerTap(void)
{
    if(_ofAppPtr)
    {
		_ofAppPtr->twoFingerTap();
    }
}

// Zoom command
// in: 
//      dZoomFactor - scaling factor of zoom in/out
//      lZx         - x-coordinate of zoom center
//      lZy         - y-coordinate of zoom center
void ofWinGestureEngine::ProcessZoom(const double dZoomFactor,const LONG lZx,const LONG lZy)
{
    if(_ofAppPtr)
    {
		_ofAppPtr->twoFingerZoom(dZoomFactor,lZx,lZy);
    }
}

// Pan/Inertia command
// in:
//      ldx - increment/decrement in x direction
//      ldy - increment/decrement in y direction
void ofWinGestureEngine::ProcessMove(const LONG ldx,const LONG ldy)
{
    if(_ofAppPtr)
    {
    }
}

// Rotate command
// in:
//      dAngle  - angle of rotation
//      lOx     - x-coordinate of the center of rotation
//      lOy     - y-coordinate of the center of rotation
void ofWinGestureEngine::ProcessRotate(const double dAngle,const LONG lOx,const LONG lOy)\
{
    if(_ofAppPtr)
    {
    }
}

void ofWinGestureEngine::setAppPointer(ofBaseTouchApp * ofAppPtr){
	_ofAppPtr = ofAppPtr;
}