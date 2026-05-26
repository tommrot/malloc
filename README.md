# my_malloc

A minimal reimplementation of `malloc` and `free` in C.

## How it works

Memory is managed on a static heap of 1MB using a **free list** strategy.

Each allocation is preceded by a `Block_header` that tracks:
- block size
- whether the block is free
- pointer to the next free block

**`alloc(size)`** — first scans the free list for a reusable block of sufficient
size; if none is found, allocates a new block from the heap.

**`my_free(ptr)`** — marks the block as free and prepends it to the free list.

**`malloc(size)`** — wraps `alloc`, rounding the requested size up to the nearest
multiple of 16 (matching standard malloc alignment behavior).

## Limitations
- Heap is fixed at 1MB
- No block splitting or coalescing (fragmentation over time)
- Not thread-safe
