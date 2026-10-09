#include <stdio.h>

int *test() {
  int a = 234;
  return &a;
}

int main(int argc, char **argv) {
  printf("Hello\n");
  int *p = test();
  printf("The value in *p = %d\n", *p); //segmentation error because res is a local variable in fun3 and it goes out of scope once fun3 returns. So r is pointing to an invalid memory location.
  return 0;
}

