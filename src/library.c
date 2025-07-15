#include <stdio.h>

void print_bits(unsigned int num) {
  for (int i = 31; i >= 0; i--) {
    printf("%d", (num >> i) & 1);
    if (i % 4 == 0) {
      printf(" ");
    }
  }
  printf("\n");
}