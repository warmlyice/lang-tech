#include <ApplicationServices/ApplicationServices.h>

void Press(int key) {
    // Create an HID hardware event source
    CGEventSourceRef src = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);

    // Create a new keyboard key press event
    CGEventRef evt = CGEventCreateKeyboardEvent(src, (CGKeyCode) key, true);

    // Post keyboard event and release
    CGEventPost (kCGHIDEventTap, evt);
    CFRelease (evt); CFRelease (src);

    usleep(60);
}
int main(int argc, char const *argv[])
{
  Press(67);
  /* code */
  printf("test24*");
  sleep(1);
  return 0;
}

//clang -framework ApplicationServices -framework Carbon main.c

// https://stackoverflow.com/questions/40546333/how-to-simulate-typing-keypresses-in-c-on-mac-os
// https://developer.apple.com/documentation/coregraphics/1456527-cgeventpost?language=objc
   // https://stackoverflow.com/questions/10179995/how-to-simulate-a-unicode-char-key-press-in-mac-os-x-using-objective-c
   /*
   CGEventRef downEvt = CGEventCreateKeyboardEvent( NULL, 0, true );
   CGEventRef upEvt = CGEventCreateKeyboardEvent( NULL, 0, false );
   UniChar oneChar = 'h';
   CGEventKeyboardSetUnicodeString( downEvt, 1, &oneChar );
   CGEventKeyboardSetUnicodeString( upEvt, 1, &oneChar );
   CGEventPost( kCGAnnotatedSessionEventTap, downEvt );
   CGEventPost( kCGAnnotatedSessionEventTap, upEvt );
    */