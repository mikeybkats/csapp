#include <stdio.h>

int is_little_endian() {
  int x = 0x012345;
  unsigned char* xchar = (unsigned char*)&x;

  printf("Bit printout for 0x012345: ");
  for (size_t i = 0; i < (size_t)sizeof(int) - 1; i++) {
    printf("%.2x ", xchar[i]);
  }
  printf("\n");

  if (xchar[0] == 0x45) {
    if (xchar[1] == 0x23) {
      if (xchar[2] == 0x01) {
        return 1;
      }
    }
  };

  return 0;
}

int main() {
  int isLittleEndian = is_little_endian();
  printf("Is host little endian: %d\n", isLittleEndian);
}
