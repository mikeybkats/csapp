#include <stdio.h>

/* 2.60 - write a function which will return an unsigned value in which byte i
 * of argument x is replaced by char b.

 example:

 replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678
 replace_byte(0x1234567, 0 0xAB) --> 0x123456AB

 */

unsigned int replace_byte(unsigned int x, int i, unsigned char b) {
  if (i > 3) {
    printf("Byte index is too large. Must be less than 4");
    return 0;
  }

  unsigned char *ax = (unsigned char *)&x;
  ax[i] = b;

  return x;
}

int main() {
  unsigned int x = 0x12345678;
  unsigned char b = 0xAB;

  printf("Original x:  %#2x\n", x);
  unsigned int nx = replace_byte(x, 2, b);
  printf("Modified x:  %#2x\n", nx);

  printf("\n");

  printf("Original x:  %#2x\n", x);
  unsigned int nx2 = replace_byte(x, 0, b);
  printf("Modified x:  %#2x\n", nx2);
}