#include <stdio.h>

#include "library.h"

/* 2.63 */

/* function srl - performs a logical right shift using an arithmetic right shift
 */
unsigned srl(unsigned x, int k) {
  /* performs shift arithmetically */
  unsigned xsra = (int)x >> k;

  int size = ((int)sizeof(int) * 8) - 1;
  for (int i = 0; i < k; i++) {
    unsigned int mask = ~(1u << (size - i));
    xsra &= mask;
  }

  return xsra;
}
/* function sra  - performs an arithmetic right shift using logical right shift
 */
int sra(int x, int k) {
  /* performs shift logically */
  unsigned int xsrl = (unsigned)x >> k;

  int size = ((int)sizeof(int) * 8) - 1;
  for (int i = 0; i < k; i++) {
    unsigned int mask = (1u << (size - i));
    xsrl |= mask;
  }

  return (int)xsrl;
}

int main() {
  unsigned int x = 0x80000000;
  printf("logical right shift before: ");
  print_bits(x);
  unsigned int n_x = srl(x, 2);
  printf("logical right shift after:  ");
  print_bits(n_x);

  printf("\n");

  unsigned int y = 0x80000000;
  printf("arithmetic right shift before: ");
  print_bits(y);
  unsigned int n_y = sra((int)y, 2);
  printf("arithmetic right shift after:  ");
  print_bits(n_y);
}

/* lesson learned: you can'y assign bits by indexing unsigned numbers. you have
 * to use bit manipulation. */