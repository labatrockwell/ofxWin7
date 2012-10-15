// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

// CGestureEngine.h
//
// Definition of helper classes for processing of gestures. During this process
// driver sends subsequent finger position information (refference point) and 
// in some cases some other information.

#pragma once
#include <windows.h>

// CGestureEngine class is abastract class that is responsible to 
// decode properly information from multi-touch driver. There are
// few pure virtual functions that are responsible for manipulation with
// object.
class CGestureEngine
{
public:
    CGestureEngine(void);
public:
    ~CGestureEngine(void);

    // Process WM_GESTURECOMMAND messages
    virtual LRESULT WndProc(HWND hWnd, WPARAM wParam, LPARAM lParam);

    // This function is called when rollover gesture is recognized
    virtual void ProcessRollover(void) = 0;

    // This function is invoked when two finger tap gesture is recognized
    virtual void ProcessTwoFingerTap(void) = 0;

    // This function is called constantly through duration of zoom in/out gesture
    virtual void ProcessZoom(const double dZoomFactor,const LONG lZx,const LONG lZy) = 0;

    // This function is called constantly through duration of panning/inertia gesture
    virtual void ProcessMove(const LONG ldx, const LONG ldy) = 0;

    // This function is called constantly through duration of rotation gesture
    virtual void ProcessRotate(const double dAngle,const LONG lOx,const LONG lOy) = 0;

private:
   
    POINT _ptFirst;        // first significant point of gesture
    POINT _ptSecond;       // second significant point of gesture
    DWORD _dwID;      // current ID
    ULONGLONG _dwArguments;    // this is holder for additional information about gesture event 
};
