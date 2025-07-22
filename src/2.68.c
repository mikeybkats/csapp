#include <stdio.h>

#include "library.h"

/*
mask with least significant n bits set to 1

examples:

n = 6 --> 0x3F // 0011 1111
n = 17 --> 0x1FFFF

assume 1 <= n <= w

*/

int lower_one_mask(int n) {
  n = 1 << (n - 1);
  return n | n - 1;
}

int main() {
  int x = 6;
  printf("x: %d", x);
  printf("\n");
  x = lower_one_mask(x);
  printf("x: %#.X\n", x);
  print_bits(x);
  printf("\n");

  x = 17;
  printf("x: %d", x);
  printf("\n");
  x = lower_one_mask(x);
  printf("x: %#.X\n", x);
  print_bits(x);
  printf("\n");

  x = 31;
  printf("x: %d", x);
  printf("\n");
  x = lower_one_mask(x);
  printf("x: %#.X\n", x);
  print_bits(x);
  printf("\n");
  return 0;
}