#include <stdio.h>

size_t next_highest_multiple_of_16(size_t n){
    return ((n + 15) / 16) * 16;
}