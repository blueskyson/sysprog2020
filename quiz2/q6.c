
#include <stdio.h>

int singleNumber(int *nums, int numsSize)
{
    int lower = 0, higher = 0;
    for (int i = 0; i < numsSize; i++) {
        lower ^= nums[i];
        lower &= ~higher;
        higher ^= nums[i];
        higher &= ~lower;
    }
    return lower;
}

int main() {
    int num1[4] = {2,2,3,2};
    int num2[7] = {0,1,0,1,0,1,99};
    printf("%d\n", singleNumber(num1, 4));
    printf("%d\n", singleNumber(num2, 7));
    return 0;
}