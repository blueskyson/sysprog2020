#include <stdio.h>
#include <stdint.h>

uint8_t hexchar2val(uint8_t in)
{
    const uint8_t letter = in & 0x40;
    const uint8_t shift = (letter >> 3) | (letter >> 6);
    return (in + shift) & 0xf;
}

int main()
{
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d ", hexchar2val('0' + i));
    }
    printf("\n");
    for (i = 0; i < 6; i++) {
        printf("%d ", hexchar2val('a' + i));
    }
    printf("\n");
    for (i = 0; i < 6; i++) {
        printf("%d ", hexchar2val('A' + i));
    }
    return 0;
}