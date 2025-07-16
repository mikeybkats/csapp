#include <stdio.h>

#include "library.h"
/* 2.65 */

/* return 1 when x contains an odd number of 1s; 0 otherwise, assume w = 32*/
int odd_ones_first_attempt(unsigned x) {
  unsigned int part1, part2, part3, part4;
  part1 = (x & 0xFF000000) >> (sizeof(int) * 6);
  part2 = (x & 0x00FF0000) >> (sizeof(int) * 4);
  part3 = (x & 0x0000FF00) >> (sizeof(int) * 2);
  part4 = (x & 0x000000FF);
  unsigned int p_xor = part1 ^ part2 ^ part3 ^ part4;
  unsigned int p_xor1 = (0xF0 & p_xor) >> 4;
  unsigned int p_xor2 = (0x0F & p_xor);
  unsigned int f_xor = p_xor1 ^ p_xor2;
  unsigned int nibble = (f_xor >> 2) ^ (f_xor & 0x3);
  unsigned int final = ((nibble >> 2) ^ (nibble & 0x3)) >> 1;
  return (int) final;
};

int odd_ones_text_book_answer(unsigned int x) {
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  return (int)x & 1;
}

int main() {
  int x = 0x32;
  printf("Odd number of positive bits in %d? %s\n", x,
         odd_ones_first_attempt(x) ? "true" : "false");

  int y = 0x32;
  printf("Odd number of positive bits in %d? %s\n", y,
         odd_ones_text_book_answer(y) ? "true" : "false");

  //   int z = 0x3;
  //   printf("Odd number of positive bits in %d? %s\n", z,
  //          odd_ones(z) ? "true" : "false");

  //   a = 0x4;
  //   printf("Odd number of positive bits in %d? %s\n", a,
  //          odd_ones(a) ? "true" : "false");
}