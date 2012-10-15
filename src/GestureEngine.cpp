// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//
// GestureEngine.cpp: implementation of CGestureEngine class

#include "GestureEngine.h"
#include <assert.h>

#define _USE_MATH_DEFINES // has to be defined to activate definition of M_PI
#include <math.h>

#define ASSERT assert


//  This function implements magic formula to convert angle
//  stored by multi-touch driver into radians. Driver stores
//  this angle as integer 
static double ArgToRadians(int arg)
{
    return ((((double)(arg) / 65535.0) * 4.0 * M_PI));
}

// Default constructor of the class.
CGestureEngine::CGestureEngine(void):
    _dwID(GID_END),
    _dwArguments(0)
{
}

// Destructor
CGestureEngine::~CGestureEngine(void)
{
}

// Main function of this class that decodes gesture information
// in:
//      hWnd        window handle
//      wParam      message parameter (message-specific)
//      lParam      message parameter (message-specific)
LRESULT CGestureEngine::WndProc(HWND hWnd, WPARAM wParam, LPARAM lParam)\
{
    POINT ptZoomCenter;
    double k;

//Exercise2-Task2-Step1 
    // read information about gesture through GESTURECOMMANDINFO structure
    GESTUREINFO  gi;
    ZeroMemory(&gi,sizeof(GESTUREINFO));
    gi.cbSize = sizeof(GESTUREINFO);
	BOOL result = GetGestureInfo((HGESTUREINFO)lParam, &gi);

	//keep track if application has handled the gesture
	BOOL fGHandled = FALSE;

    if(result)
    {
//Exercise2-Task3-Step1
		//switch on the identifers to determine which gesture is being processed
        switch(gi.dwID)
        {
        //GID_BEGIN and GID_END denote the start/end of a gesture sequence
		case GID_BEGIN:
		case GID_END:

            fGHandled = TRUE;
            break;

		// GID_PAN:
        //      _ptFirst - first point of moving vector (middle point between two fingers)
        //      _dwArguments - not important for this gesture

		case GID_PAN:
			if (gi.dwFlags & GF_BEGIN)
			{
//Exercise2-Task4-Step1 

				_dwID = gi.dwID;
                _dwArguments = gi.ullArguments;
                _ptFirst.x = gi.ptsLocation.x;
                _ptFirst.y = gi.ptsLocation.y;
                ScreenToClient(hWnd,&_ptFirst);
                break;         

			}
			else 
            {
				// We read the second point of this gesture. It's a middle point
                // between fingers in this new position
//Exercise2-Task4-Step3

				_ptSecond.x = gi.ptsLocation.x;
                _ptSecond.y = gi.ptsLocation.y;
                ScreenToClient(hWnd,&_ptSecond);

                // We apply move operation the the object
                ProcessMove(_ptSecond.x-_ptFirst.x,_ptSecond.y-_ptFirst.y);

                InvalidateRect(hWnd,NULL,TRUE);

				// We have to copy second point into first one to prepare
                // for next pan message.
                _ptFirst.x = _ptSecond.x;
                _ptFirst.y = _ptSecond.y;

			}
				
			fGHandled = TRUE;

			break;
	
		// GID_ZOOM:
        //      m_ptFirst - we store information about middle point between two fingers that
        //                  are placed down
        //      _dwArguments - distance between fingers 	
		case GID_ZOOM:
			if (gi.dwFlags & GF_BEGIN)
			{
//Exercise3-Task2-Step1 

				_dwID = gi.dwID;
                _dwArguments = gi.ullArguments;
                _ptFirst.x = gi.ptsLocation.x;
                _ptFirst.y = gi.ptsLocation.y;
                ScreenToClient(hWnd,&_ptFirst);

                break;              
			}
			else if (gi.dwFlags & GF_END)
            {
				//at end of gesture, zero the arguments
                _dwArguments = 0;
            }
            else 
            {
				 // We read here the second point of the gesture. This is middle point between 
                // fingers in this new position.
				//Exercise3-Task2-Step1 

                _ptSecond.x = gi.ptsLocation.x;
                _ptSecond.y = gi.ptsLocation.y;
                ScreenToClient(hWnd,&_ptSecond);

                // We have to calculate zooming center point and coefficient of straching
                // _dwArguments holds the old distance between two fingers and new 
                // distance is stored in gi.dwArguments
                ptZoomCenter.x = (_ptFirst.x + _ptSecond.x)/2;
                ptZoomCenter.y = (_ptFirst.y + _ptSecond.y)/2;
                k = (double)gi.ullArguments/_dwArguments;

                // Now we process zooming in/out of object
                ProcessZoom(k,ptZoomCenter.x,ptZoomCenter.y);

                InvalidateRect(hWnd,NULL,TRUE);

                // Now we have to store new information as a starting information 
                // for next step in this gesture.
                _ptFirst.x = _ptSecond.x;
                _ptFirst.y = _ptSecond.y;   
                _dwArguments = gi.ullArguments;
            }

            fGHandled = TRUE;
				
			break;

		// GID_ROTATE:
        //      _ptFirst - center of rotation (position of first finger placed down)
        //      _dwArguments - initial rotation angle
		
		case GID_ROTATE:
			if (gi.dwFlags & GF_BEGIN)
            {
//Exercise2-Task5-Step1 

				_dwID = gi.dwID;
                _dwArguments = gi.ullArguments;
                _ptFirst.x = gi.ptsLocation.x;
                _ptFirst.y = gi.ptsLocation.y;
                ScreenToClient(hWnd,&_ptFirst);
                ProcessRotate(ArgToRadians(gi.ullArguments),_ptFirst.x,_ptFirst.y);
                InvalidateRect(hWnd,NULL,TRUE);

            }
            else
            {
//Exercise2-Task5-Step2 

                ProcessRotate(ArgToRadians(gi.ullArguments-_dwArguments),_ptFirst.x,_ptFirst.y);
                InvalidateRect(hWnd,NULL,TRUE);
                _dwArguments = gi.ullArguments;

            }

			fGHandled = TRUE;

			break;
		
		// GID_TWOFINGERTAP:
		// This is a type of gesture that can be processed right away without
        // storing information for later usage.
		case GID_TWOFINGERTAP:
//Exercise3-Task1-Step1 

			ProcessTwoFingerTap();
			InvalidateRect(hWnd,NULL,TRUE);

			fGHandled = TRUE;

			break;

		default:

            fGHandled = FALSE;

            break;
        }
    }

	// Notify the system that this application has handled the gesture
    if (fGHandled)
    {
        CloseGestureInfoHandle((HGESTUREINFO)lParam);
    }
	//if the application did not handle the gesture, pass it back to the system
    else
    {
        DefWindowProc(hWnd, WM_GESTURE, wParam, lParam);
    }

	// redraw the window
    InvalidateRect(
		hWnd,
		NULL,
        FALSE
        );

	//   Since we do handle all gesture commands we have to return 
    //   cumulative flag shifted left by one position (that's what
    //   main WndPrc procedure expects
    return 
    (
        GID_ZOOM |
        GID_PAN |
        GID_ROTATE |
        GF_INERTIA |
        GID_TWOFINGERTAP
    ) << 1;
}
