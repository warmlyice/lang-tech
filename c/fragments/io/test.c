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
