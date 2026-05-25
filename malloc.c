#include "alloc.h"
#include "next_highest_multiple_of_16.h"
#include "block.h"
#include <stdlib.h>

void *malloc(size_t size){ 
    size_t bits_16_size = next_multiple_of_16(size); // because malloc function approximates to excess in 16's multiples
    void *p = alloc(bits_16_size);    // call to alloc function to get pointer to allocated memory 
    return p;
}