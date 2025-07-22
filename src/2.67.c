#include <stdio.h>

/* The following code does not run properly on some machines*/
int bad_int_size_is_32() {
  int set_msb = 1 << 31;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wshift-count-overflow"
  int beyond_msb = 1 << 32;
#pragma clang diagnostic pop

  return set_msb && beyond_msb;
}

int better_int_size_is_32() {
  int set_msb = 1 << 31;

  return set_msb < 0 && set_msb != 0;
}

int better_int_size_is_16() {
  int set_msb = 1 << 15;

  return set_msb < 0 && set_msb != 0;
}

int main() {
  printf("int size is 32? %s\n", bad_int_size_is_32() ? "true" : "false");
  printf("int size is 32? %s\n", better_int_size_is_32() ? "true" : "false");
  printf("int size is 16? %s\n", better_int_size_is_16() ? "true" : "false");
  return 0;
}