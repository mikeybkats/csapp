#include <stdio.h>

#include "library.h"

/* 2.62 - write a function int_shifts_are_arithmetic() that yields 1 when run on
 * a machine that uses arithmetic right shifts for data type int and yields 0
 * otherwise.*/

/*
check to see if a machine performs arithmetic or logical shifts
1000 >> 1 = 1100 (arithmetic)
1000 >> 1 = 0100 (logical)
*/
int int_shifts_are_arithmetic() {
  // sizeof(int) -- either 4 or 8 bytes, but usually 4 bytes on 32 and 64 bit
  // systems.
  int ms_bit =
      (int)(1 << (sizeof(int) * 8 - 1));  // multply by the number of bits
  ms_bit = ms_bit >> 1;  // shift one bit to check for the 1 carry which only
                         // happens on arithmetic bit shifts:

  print_bits((unsigned int)ms_bit);

  return ms_bit & (int)(1 << (sizeof(int) * 8 - 1));
}

int main() {
  int result = int_shifts_are_arithmetic();
  printf("Arithmetic shifts: %s\n", result ? "Yes" : "No");
  return 0;
}