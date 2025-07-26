#include <stdio.h>

#include "library.h"

/*
Do rotating left shift

assume 0 <= n < w

Examples:

x = 0x12345678
w = 32

n = 4 --> 0x23456781
n  20 --> 0x67812345

*/

int rotating_left_shift(int n, int x) {
  // (x << n) | (x >> (32 - n)
  int shift = n & 31;  // use & 31 to mask any bits above 31. works like modulo
  int rotation = 32 - shift;
  int leftShift = x << shift;
  int rightShift = x >> rotation;
  return leftShift | rightShift;
}

int main() {
  int x = 0x12345678;

  printf("%#.2x\n", x);
  printf("%#.2x\n", rotating_left_shift(4, x));

  printf("\n");

  printf("%#.2x\n", x);
  printf("%#.2x\n", rotating_left_shift(20, x));

  printf("\n");

  printf("%#.2x\n", x);
  printf("%#.2x\n", rotating_left_shift(8, x));
  return 0;
}