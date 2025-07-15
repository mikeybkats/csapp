#include <stdio.h>

#include "library.h"

/* 2.64 */

/* return 1 when any odd bit of x equals 1; 0 otherwise. assume w = 32 */
int any_odd_one(unsigned x) {
  return (int)!!(0xAAAAAAAA & x);
};

int main() {
  int x = 2;   // 0010 bit 1
  int y = 10;  // 1010 bit 1 and 3
  int z = 11;  // 1011 bit 0, 1 and 3

  printf("2 has an odd bit: %s\n", any_odd_one(x) ? "true" : "false");
  printf("10 has an odd bit: %s\n", any_odd_one(y) ? "true" : "false");
  printf("11 has an odd bit: %s\n", any_odd_one(z) ? "true" : "false");
}