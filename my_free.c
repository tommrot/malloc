#include "block.h"
#include "alloc.h"

void my_free(void *ptr){
    Block_header *p = (Block_header *)ptr - 1;   //casting of parameter into Block_header, ptr - 1 come back to header
    p->free = 1;   // we change value of *p.free in 1
    p->next = free_list;   // we assign actual pointer to first element of free_list in next
    free_list = p;   // first element of free_list is assigned to headers of parameter
}