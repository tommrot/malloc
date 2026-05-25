#ifndef ALLOC_H
#define ALLOC_H

#include <stdlib.h>
#include "block.h"

Block_header *free_list = NULL;

void *alloc(size_t size);

#endif