#include <stdio.h>

#include "library.h"

/* 2.66  Generate a mask indicating leftmost 1 in x (positive bit). Assume w=32.
 * For example, 0xFF00 --> 0x8000, and 0x6600 --> 0x4000
 * If x = 0, then return 0
 *
 * hint: first transform x into a bit vector of the form [0...011... 1]
 */
int leftmost_one(unsigned x) {
  x |= x >> 16;
  x |= x >> 8;
  x |= x >> 4;
  x |= x >> 2;
  x |= x >> 1;

  return (int)(x & (~x >> 1));
}

int main() {
  int x = 0xEC;
  printf("x:  ");
  print_bits(x);
  int y = leftmost_one(x);
  printf("y:  ");
  print_bits(y);
  printf("\n");

  x = 0xe;
  y = leftmost_one(x);
  printf("x:  ");
  print_bits(x);
  printf("y:  ");
  print_bits(y);
  printf("\n");

  x = 0xF;
  y = leftmost_one(x);
  printf("x:  ");
  print_bits(x);
  printf("y:  ");
  print_bits(y);
  printf("\n");

  x = 0xAbDF2e;
  y = leftmost_one(x);
  printf("x:  ");
  print_bits(x);
  printf("y:  ");
  print_bits(y);
  printf("\n");

  x = 0x341212F;
  y = leftmost_one(x);
  printf("x:  ");
  print_bits(x);
  printf("y:  ");
  print_bits(y);
  printf("\n");

  x = 0xA8BB;
  y = leftmost_one(x);
  printf("x:  ");
  print_bits(x);
  printf("y:  ");
  print_bits(y);
  printf("\n");
}