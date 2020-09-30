#ifndef __LIB_KERNEL_BITMAP_HANDLER_H
#define __LIB_KERNEL_BITMAP_HANDLER_H

/* Bitmap handler.

   Bitmap handler is resonsible for using bitmaps.
*/

/* Receives and executes a command. */
void bitmap_handler_invoke (const char *cmd, const int argc,
                            const char *argv[]);

#endif /* lib/kernel/bitmap_handler.h */
