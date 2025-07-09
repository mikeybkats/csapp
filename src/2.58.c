#include <stdio.h>

int is_little_endian() {
  int x = 1;
  unsigned char* xchar = (unsigned char*)&x;

  return xchar[0] == 1;
}

int main() {
  int isLittleEndian = is_little_endian();
  printf("Is host little-endian: %s\n", isLittleEndian ? "true" : "false");
}
