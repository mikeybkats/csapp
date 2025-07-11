#include <stdio.h>

/* 2.61 - write c expressions that evaluate to 1 when the following conditions
 * are true and to 0 when they are false. Assume x is of type int */

void print_bits(unsigned int num) {
  for (int i = 31; i >= 0; i--) {
    printf("%d", (num >> i) & 1);
    if (i % 4 == 0) {
      printf(" ");
    }
  }
  printf("\n");
}

int main() {
  unsigned int x;
  unsigned int y;

  /* A. Any bit of x equals 1 */
  // !!x
  x = 0x8080;
  y = 0x0000;
  print_bits(!!x);  // should return 1
  print_bits(!!y);  // should return 0

  /* B. Any bit of x equals 0 */
  x = 0x01;
  y = 0xFFFFFFFF;
  print_bits(!!(x ^ ~0U));  // should return 1
  print_bits(!!(y ^ ~0U));  // should return 0

  /* C. Any bit in the least significant byte of x equals 1 */

  /* D. Any bit in the most significant byte of x equals 0 */
}