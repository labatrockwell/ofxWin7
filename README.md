ofxWin7
=======

Simple helper classes to setup Windows 7 touch in openFrameworks. Supports both Windows 7 touch events as well as a gestures. 

Based on code from the OF forum here: http://forum.openframeworks.cc/index.php/topic,3120.new.html#new

Setting Up
=======
* You'll need to add the following preprocessor defs to your app to compile in Windows 7+ touch support:
  * ```_WIN32_WINNT=0x0601```
  * ```POCO_NO_UNWINDOWS```
