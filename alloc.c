#include <stdlib.h>

static unsigned char heap[1024*1024];
static unsigned char *heap_ptr = heap;


void *alloc(size_t size){
    void *p = heap_ptr;
    heap_ptr += size;
    return p;
}