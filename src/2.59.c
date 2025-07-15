#include <stdio.h>

#include "library.h"

/* 2.59 - an expression that yields a new word consisting of the least
 * significant byte of x and the remaining bytes of y. */

int is_little_endian() {
  int x = 1;
  unsigned char *xchar = (unsigned char *)&x;

  // In little-endian, the least significant byte (1) will be at index 0
  // In big-endian, the least significant byte (1) will be at the highest index
  return xchar[0] == 1;
}

int least_most_word(int x, int y) {
  unsigned char *x_word = (unsigned char *)&x;
  unsigned char *y_word = (unsigned char *)&y;

  if (is_little_endian()) {
    // most significant byte last index
    y_word[0] = x_word[0];
  } else {
    // most significant byte is last index
    y_word[sizeof(int) - 1] = x_word[sizeof(int) - 1];
  }

  return y;
}

int main() {
  int x = 0x456789;
  int y = 0x987654;
  int z = least_most_word(x, y);

  printf("x:   %#8x\n", x);
  printf("y:   %#8x\n", y);
  printf("lmw: %#8x\n", z);
}