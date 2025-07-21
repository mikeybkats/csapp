#include <stdio.h>

#include "library.h"

/* 2.66  Generate a mask indicating leftmost 1 in x (positive bit). Assume w=32.
 * For example, 0xFF00 --> 0x8000, and 0x6600 --> 0x4000
 * If x = 0, then return 0
 *
 * hint: first transform x into a bit vector of the form [0...011... 1]
 */
int leftmost_one(unsigned x) {  // 0xFF00 1111 1111 0000 0000
  // 0x8000 1000 0000 0000 0000
  // unsigned int a;
  // a = x >> 31;
  // a |= x >> 30;
  // a |= x >> 29;
  // a |= x >> 28;
  // a |= x >> 27;
  // a |= x >> 26;
  // a |= x >> 25;
  // a |= x >> 24;
  // a |= x >> 23;
  // a |= x >> 22;
  // a |= x >> 21;
  // a |= x >> 20;
  // a |= x >> 19;
  // a |= x >> 18;
  // a |= x >> 17;
  // a |= x >> 16;
  // a |= x >> 7;
  // a |= x >> 6;
  // a |= x >> 5;
  // a |= x >> 4;
  // a |= x >> 3;
  // a |= x >> 2;
  // a |= x >> 1;

  // return (int)(x & (~a));
  unsigned int mask = ((x << 1) | x) & ((x >> 1) | x);
  print_bits(mask);

  return (int)((x & (x >> 1)) & (x & (x << 1))) << 1;
}

int main() {
  int x = 0xEC;
  printf("x         : ");
  print_bits(x);
  int y = leftmost_one(x);
  printf("y:  ");
  print_bits(y);
  printf("\n");

  // printf("x >> 1    : ");
  // print_bits(x >> 1);

  // printf("x << 1    : ");
  // print_bits(x << 1);

  // print_bits(((x << 1) | x) & ((x >> 1) | x));
  // print_bits((x >> 1) | x);

  // printf("-x & x   : ");
  // print_bits((-x) & x);

  // printf("-x       : ");
  // print_bits(-x);

  // printf("-x | x   : ");
  // print_bits((-x) | x);

  // printf("?        : ");
  // print_bits(((x & (x >> 1)) & (x & (x << 1))) << 1);

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