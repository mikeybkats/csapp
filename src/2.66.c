#include <stdio.h>

/* 2.66 */

/*
 * Generate a mask indicating leftmost 1 in x (positive bit). Assume w=32.
 * For example, 0xFF00 --> 0x8000, and 0x6600 --> 0x4000
 * If x = 0, then return 0
 */
int leftmost_one(unsigned x) {
  unsigned char* ax =
      (unsigned char*)&x;  // tells c to interpret this as 8 bit chunks
  //   unsigned int* ax = (unsigned int*)&x; // interprets this as 32 bit
  unsigned int b1, b2, b3, b4;
  b1 = ax[0];
  b2 = ax[1];
  b3 = ax[2];
  b4 = ax[3];

  printf("b1: %#4X\n", b1);
  printf("b2: %#4X\n", b2);
  printf("b3: %#4X\n", b3);
  printf("b4: %#4X\n", b4);

  // 0xFF00 1111 1111 0000 0000
  // 0x8000 1000 0000 0000 0000

  // 0x3821 0011 0100 0010 0001
  // 0x2000 0010 0000 0000 0000
  return 0;
};

int main() {
  int x = 0xABCDEF12;
  printf("x:  %#4X\n", x);
  leftmost_one(x);
}