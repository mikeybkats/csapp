/* 2.70 write code for the following prototype */

#include <stdio.h>

#include "library.h"

// returns most significant bit
int leftmost_one(unsigned x) {
  x |= x >> 16;
  x |= x >> 8;
  x |= x >> 4;
  x |= x >> 2;
  x |= x >> 1;

  return (int)(x & (~x >> 1));
}

// masks lower n bits
int lower_one_mask(int n) {
  n = 1 << (n - 1);
  return n | n - 1;
}

/*
 * Return 1 when x can be represented as an n-bit, 2's compliment number; 0
 * otherwise Assume 1 <= n <= w
 */
int fits_bits(int x, int n) {
  int mask = lower_one_mask(n);
  int msb = leftmost_one(x);
  int r = msb & mask;
  return r;
};

int main() {
  int x = 10031;  // 1010
  int n = 8;      // max 11 = 111

  int fits = fits_bits(x, n);

  printf("%d fits in %d bits? %s\n", x, n, fits ? "true" : "false");

  //   print_bits(n);
  //   print_bits(n |= n >> 16);
  //   print_bits(n |= n >> 8);
  //   print_bits(n |= n >> 4);
  //   print_bits(n |= n >> 2);
  //   print_bits(n |= n >> 1);
  //   print_bits(~n);
  //   print_bits(~n >> 1);
  //   print_bits((~n >> 1) & n);
}