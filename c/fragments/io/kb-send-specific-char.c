
#include <Carbon/Carbon.h>
#include "press.h"
/* Returns string representation of key, if it is printable.
 * Ownership follows the Create Rule; that is, it is the caller's
 * responsibility to release the returned object. */
CFStringRef createStringForKey(CGKeyCode keyCode)
{
   TISInputSourceRef currentKeyboard = TISCopyCurrentKeyboardInputSource();
   CFDataRef layoutData =
      TISGetInputSourceProperty(currentKeyboard,
                                kTISPropertyUnicodeKeyLayoutData);
   const UCKeyboardLayout *keyboardLayout =
      (const UCKeyboardLayout *)CFDataGetBytePtr(layoutData);

   UInt32 keysDown = 0;
   UniChar chars[4];
   UniCharCount realLength;

   UCKeyTranslate(keyboardLayout,
                  keyCode,
                  kUCKeyActionDisplay,
                  0,
                  LMGetKbdType(),
                  kUCKeyTranslateNoDeadKeysBit,
                  &keysDown,
                  sizeof(chars) / sizeof(chars[0]),
                  &realLength,
                  chars);
   CFRelease(currentKeyboard);

   return CFStringCreateWithCharacters(kCFAllocatorDefault, chars, 1);
}
/* Returns key code for given character via the above function, or UINT16_MAX
 * on error. */
CGKeyCode keyCodeForChar(const char c)
{
   static CFMutableDictionaryRef charToCodeDict = NULL;
   CGKeyCode code;
   UniChar character = c;
   CFStringRef charStr = NULL;

   /* Generate table of keycodes and characters. */
   if (charToCodeDict == NULL) {
      size_t i;
      charToCodeDict = CFDictionaryCreateMutable(kCFAllocatorDefault,
                                                 128,
                                                 &kCFCopyStringDictionaryKeyCallBacks,
                                                 NULL);
      if (charToCodeDict == NULL) return UINT16_MAX;

      /* Loop through every keycode (0 - 127) to find its current mapping. */
      for (i = 0; i < 128; ++i) {
         CFStringRef string = createStringForKey((CGKeyCode)i);
         if (string != NULL) {
            CFDictionaryAddValue(charToCodeDict, string, (const void *)i);
            CFRelease(string);
         }
      }
   }

   charStr = CFStringCreateWithCharacters(kCFAllocatorDefault, &character, 1);

   /* Our values may be NULL (0), so we need to use this function. */
   if (!CFDictionaryGetValueIfPresent(charToCodeDict, charStr,
                                      (const void **)&code)) {
      code = UINT16_MAX;
   }

   CFRelease(charStr);
   return code;
}
void Press(int key) {
  // Create an HID hardware event source
  CGEventSourceRef src = CGEventSourceCreate(kCGEventSourceStateHIDSystemState);
  // Create a new keyboard key press event
  CGEventRef evt = CGEventCreateKeyboardEvent(src, (CGKeyCode) key, true);
  // Post keyboard event and release
  CGEventPost (kCGHIDEventTap, evt);
  CFRelease (evt);
  CFRelease (src);
  // usleep(60);
}
int main(int argc, char const *argv[]) {
  // int key = keyCodeForChar('^');
  int key = keyCodeForChar('g');
  Press(key);
  Press(key);
  printf("%d", key);
  return 0;
}
