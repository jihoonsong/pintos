#ifndef __LIB_KERNEL_HASH_HANDLER_H
#define __LIB_KERNEL_HASH_HANDLER_H

/* Hash handler.

   Hash handler is responsible for using hash tables.
*/

/* Receives and executes a command. */
void hash_handler_invoke (const char *cmd, const int argc,
                          const char *argv[]);

#endif /* lib/kernel/hash_handler.h */
