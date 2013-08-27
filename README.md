Note
-------
This repo will remain in place to support some older projects we've been working on, but is mostly frozen in time. Check out momo-the-monster's more actively maintained Windows touch addon here for some great new features! 
* https://github.com/momo-the-monster/ofxWinTouch


ofxWin7
=======
Compatible with openFrameworks 0.8.0

Simple helper classes to setup Windows 7 touch in openFrameworks. Supports both Windows 7 touch events as well as a gestures. 
Based on code from the OF forum here: http://forum.openframeworks.cc/index.php/topic,3120.new.html#new

Setting Up
=======
* You'll need to add the following preprocessor defs to your app to compile in Windows 7+ touch support:
  * ```_WIN32_WINNT=0x0601```
  * ```POCO_NO_UNWINDOWS```
