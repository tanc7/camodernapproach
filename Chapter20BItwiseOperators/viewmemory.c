//
// Created by ctlister on 12/7/22.
//
#include <ctype.h>
#include <stdio.h>
// Book is outdated

/* You can't move a pointer from a 64-bit register to a 32-bit register, illegal operation thats why it segfaults
 * → 0x5555555552ca <main+225>       movzx  eax, BYTE PTR [rax]

 * */
typedef unsigned char BYTE;
int main(void) {
    unsigned int addr;
    int i, n;
    //int i, n, m;
//    m = (int) &main;
    BYTE *ptr;
    printf("Address of addr variable %x\n", (unsigned int) &addr);
    printf("\nEnter a (hex) address: ");
    scanf("%x",&addr);
    printf("Enter a number of bytes to view: ");
    scanf("%d", &n);
    printf("\n");
    printf("Address\tBytes\tCharacters\n");
    for (; n >0; n-=10) {
        printf("%8X ", (unsigned int) ptr);
        for (i=0;i<10 && i<n; i++ ) {
            BYTE ch = *(ptr+i);
            if (!isprint(ch))
                ch = '.';
            printf("%c",ch);
         //   ptr += 10;
        }
        printf("\n");
        ptr += 10;
    }
    return 0;
}