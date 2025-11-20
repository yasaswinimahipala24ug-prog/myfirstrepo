#include <stdio.h>

int main() {
    int a = 10, b = 20, sum = 0;

    __asm__ __volatile__ (
        ".intel_syntax noprefix\n\t"
        "mov eax, %1\n\t"
        "add eax, %2\n\t"
        "mov %0, eax\n\t"
        ".att_syntax prefix\n\t"
        : "=r" (sum)
        : "r" (a), "r" (b)
        : "eax"
    );

    printf("Sum: %d\n", sum);
    
}

