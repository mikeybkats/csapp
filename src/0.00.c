#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc > 1) {
    printf("Hello world, love %s.\n", argv[1]);
  } else {
    printf("Hello world.\n");
  }

  return 0;
}