#ifndef BLOCK_H
#define BLOCK_H

#include <stdlib.h>

typedef struct Block_header {
    size_t size;    //size for datas, not header's size
    int free;         
    Block_header *next;
} Block_header;

#endif