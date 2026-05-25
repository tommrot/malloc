#ifndef BLOCK_H
#define BLOCK_H

#include <stdlib.h>

typedef struct Block_header {
    size_t size;    //size for datas, not header's size
    int free;         
    struct Block_header *next;   //because compiler has not yet created type Block_header
} Block_header;

#endif