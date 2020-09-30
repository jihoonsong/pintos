#ifndef __LIB_KERNEL_LIST_HANDLER_H
#define __LIB_KERNEL_LIST_HANDLER_H

/* List handler.

   List handler is responsible for using doubly linked lists.
*/

/* Receives and executes a command. */
void list_handler_invoke (const char *cmd, const int argc,
                          const char *argv[]);

#endif /* lib/kernel/list_handler.h */
