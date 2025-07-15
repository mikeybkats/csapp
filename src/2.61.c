#include <limits.h>
#include <stdio.h>

#include "library.h"

/* 2.61 - write c expressions that evaluate to 1 when the following conditions
 * are true and to 0 when they are false. Assume x is of type int */

int get_msb(int x) {
  /* Shift b w-8 */
  int shift_val = (sizeof(int) - 1)
                  << 3;  // 3 shifted left 3 places:  0001 1000 ie 24

  /* Arithmetic shift */
  int xright = x >> shift_val;  // x shifted 24 places to the right puts the
                                // upper 8 bits at the bottom

  /* Zero all but lsb */
  return 0xFF & xright;  // bit mask lower 8 bits
}

int get_lsb(int x) {
  return 0xFF & x;
}

int main() {
  int x;
  int y;

  /* A. Any bit of x equals 1 */
  // !!x
  x = 0x8080;
  y = 0x0000;
  printf("Any bit of x equals 1?\n");
  print_bits(x);    // should return 1
  print_bits(!!x);  // should return 1
  printf("\n");
  print_bits(y);    // should return 1
  print_bits(!!y);  // should return 0
  printf("\n");

  /* B. Any bit of x equals 0 */
  // !!(x ^ ~0U)
  x = 0x0FFFFFFF;
  y = 0xFFFFFFFF;
  printf("Any bit of x equals 0?\n");
  print_bits(x);                 // should return 1
  print_bits(!!(x ^ UINT_MAX));  // should return 1
  printf("\n");
  print_bits(y);                 // should return 1
  print_bits(!!(y ^ UINT_MAX));  // should return 0
  printf("\n");

  /* C. Any bit in the least significant byte of x equals 1 */
  // !!(x & 0xFF)
  x = 0x1104;
  y = 0x4100;
  printf("Any bit in the least significant byte of x equals 1?\n");
  print_bits(x);
  print_bits(!!(x & 0xFF));
  printf("\n");

  print_bits(y);
  print_bits(!!(y & 0xFF));
  printf("\n");

  /* D. Any bit in the most significant byte of x equals 0 */
  // !!(get_msb(x) ^ 0xFF)
  x = 0x00004451;
  int topx = get_msb(x);
  y = 0xFF000011;
  int topy = get_msb(y);

  printf("Any bit in the most significant byte of x equals 0\n");
  print_bits(x);
  print_bits(!!(topx ^ 0xFF));
  printf("\n");

  print_bits(y);
  print_bits(!!(topy ^ 0xFF));
  printf("\n");
}