#include <stdio.h>

int next_highest_multiple_of_16(int n){
    return (n / 16) * 16 + 16;
}


int main(void){
    int m = next_highest_multiple_of_16(17);
    printf("%d\n", m);
}