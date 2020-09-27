#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

const uint32_t D = 3;
#define M ((uint64_t)(UINT64_C(0xFFFFFFFFFFFFFFFF) / (D) + 1))

uint32_t quickmod(uint32_t n)
{   uint64_t quotient = ((__uint128_t) M * n) >> 64;
    return n - quotient * D;
}

bool divisible(uint32_t n)
{
    return n * M <= M - 1;
}

int main()
{
    printf("%u ", quickmod(1));
    printf("%u ", quickmod(2));
    printf("%u ", quickmod(3));
    printf("\n");
    printf("%d ", divisible(1));
    printf("%d ", divisible(2));
    printf("%d ", divisible(3));
}