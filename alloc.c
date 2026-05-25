#include <stdlib.h>
#include "block.h"
#include <stdio.h>

static unsigned char heap[1024*1024];
static unsigned char *heap_ptr = heap;   //it's char for moving of 1 byte

Block_header *free_list = NULL;   //we create free_list as pointer because we don't know how many free blocks will be, so we use pointer instead of array

void *alloc (size_t size){
    Block_header *p = free_list;   //because we want to keep track of first element's address of free_list, we'll operate on pointer p
    while (p != NULL){
        if (size < p->size  && p->free == 1){   //because we need enough space and control of free state of block
            p->free = 0;
            return (void *)(p + 1);      //beacause we want pointer to datas, and not to header, p + 1 is evaluated, with void* we access to data skipping header
        }
        p = p->next;    //because if not available we'll scroll the list free_list, and pointer p will be equal to pointer to next element.
    }
    Block_header *q = heap_ptr;

    //control if there's enough space in heap memory for size request allocation
    if (heap + sizeof(heap) <= size + heap_ptr){
        printf("allocation failed, not enough space\n");
        return NULL;
    } else {
        heap_ptr += sizeof(Block_header) + size;
        q->free = 0;
        q->size = size;
        q->next = NULL;
        return (void *)(q + 1);    ////beacause we want pointer to datas, and not to header, with (p + 1) we skip header, (p is Block_header type)
    }   
}
