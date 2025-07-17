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

int odd_ones_second_attempt(unsigned x) {
  x = (((x & 0xFFFF0000) >> 16)) ^ (x & 0x0000FFFF);
  x = (((x & 0xFF00) >> 8)) ^ (x & 0xFF);
  x = (((x & 0xF0) >> 4)) ^ (x & 0xF);
  x = (((x & 0xC) >> 2)) ^ (x & 0x3);
  return (int)x & 1;
};

int odd_ones_without_masks_third_attempt(unsigned x) {
  x = ((x >> 16)) ^ x;  // 32→16 bits
  x = ((x >> 8)) ^ x;   // 16→8 bits
  x = ((x >> 4)) ^ x;   // 8→4 bits
  x = ((x >> 2)) ^ x;   // 4→2 bits
  return (int)x & 1;    // 2→1 bit
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
  int x = 0x123456F9;
  printf("Odd number of positive bits in %d? %s\n", x,
         odd_ones_second_attempt(x) ? "true" : "false");

  int y = 0x123456F9;
  printf("Odd number of positive bits in %d? %s\n", y,
         odd_ones_text_book_answer(y) ? "true" : "false");

  int z = 0x123456F9;
  printf("Odd number of positive bits in %d? %s\n", z,
         odd_ones_without_masks_third_attempt(z) ? "true" : "false");

  printf("\n");

  x = 0x1C34A;
  printf("Odd number of positive bits in %d? %s\n", x,
         odd_ones_second_attempt(x) ? "true" : "false");

  y = 0x1C34A;
  printf("Odd number of positive bits in %d? %s\n", y,
         odd_ones_text_book_answer(y) ? "true" : "false");

  z = 0x1C34A;
  printf("Odd number of positive bits in %d? %s\n", z,
         odd_ones_without_masks_third_attempt(z) ? "true" : "false");

  printf("\n");

  x = 0x21D;
  printf("Odd number of positive bits in %d? %s\n", x,
         odd_ones_second_attempt(x) ? "true" : "false");

  y = 0x21D;
  printf("Odd number of positive bits in %d? %s\n", y,
         odd_ones_text_book_answer(y) ? "true" : "false");

  z = 0x21D;
  printf("Odd number of positive bits in %d? %s\n", z,
         odd_ones_without_masks_third_attempt(z) ? "true" : "false");
}