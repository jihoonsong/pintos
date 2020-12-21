#include "vm/frametab.h"
#include <debug.h>
#include <list.h>
#include "threads/palloc.h"
#include "threads/synch.h"

/* A frame table. Frames are inserted in FIFO manner
   for the clock page replacement algorithm. */
static struct list frames;

/* A frame lock. */
static struct lock frame_lock;

/* Initialize the frame table and the frame lock. */
void
frametab_init (void)
{
  list_init (&frames);
  lock_init (&frame_lock);
}

/* Allocate a new frame and return its kernel virtual address.
   If there is no empty slot in the frame table, one frame will be
   selected as a victim and be evicted to allocate a new frame. */
void *
frametab_get_frame (enum palloc_flags flags, void *upage)
{
  if (!lock_held_by_current_thread (&frame_lock))
    lock_acquire (&frame_lock);

  void *kpage = palloc_get_page (PAL_USER | flags);
  if (kpage == NULL)
    {
      // TODO: Swapping have to occur.
      PANIC ("frametab_get_frame: out of frames");
    }

  // TODO: Construct a new frame and add to frames.

  lock_release (&frame_lock);

  return kpage;
}

/* Remove the frame at KPAGE from the frame table and free it. */
void
frametab_free_frame (void *kpage)
{
  if (!lock_held_by_current_thread (&frame_lock))
    lock_acquire (&frame_lock);

  // TODO: Remove the frame at KPAGE from frames.

  palloc_free_page (kpage);

  lock_release (&frame_lock);
}
