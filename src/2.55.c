#include <stdio.h>
#include <stdlib.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
  for (size_t i = 0; i < len; i++) {
    printf(" %.2x", start[i]);
  }
  printf("\n");
}

void show_int(int x) {
  printf("x: %-12d hexadecimal: ", x);
  show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x) {
  printf("x: %-12f hexadecimal: ", x);
  show_bytes((byte_pointer)&x, sizeof(x));
}

void show_pointer(void *x) {
  printf("x: %-12p hexadecimal: ", x);
  show_bytes((byte_pointer)&x, sizeof(x));
}

void test_show_bytes(int val) {
  int ival = val;
  float fval = (float)ival;
  int *pval = &ival;

  show_int(ival);
  show_float(fval);
  show_pointer(pval);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Please pass an integer as input.\n");
    return 1;
  }
  char *endptr = malloc(10);
  int val = (int)strtol(argv[1], &endptr, 10);

  if (*endptr != '\0') {
    printf("Invalid integer: %s\n", argv[1]);
    return 1;
  }

  test_show_bytes(val);
}